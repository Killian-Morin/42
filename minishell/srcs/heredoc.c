/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:50:56 by killian           #+#    #+#             */
/*   Updated: 2023/10/24 09:41:33 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	prepare_execute_heredoc(char *delimiter)
{
	int	i;
	int	expand;

	i = 0;
	expand = 0;
	while (delimiter[i])
	{
		if (delimiter[i] == '\'' || delimiter[i] == '\"')
			expand = 1;
		i++;
	}
	return (expand);
}

int	execute_heredoc(int fd, char *delimiter, t_data *data)
{
	int		expand;
	pid_t	pid;

	expand = prepare_execute_heredoc(delimiter);
	delimiter = delete_quotes(delimiter);
	if (!delimiter)
		return (1);
	pid = fork();
	if (pid == -1)
		exit_error("fork", "fork failed", EX_OSERR);
	else if (pid == 0)
		heredoc_child(fd, expand, delimiter, data);
	else
	{
		if (heredoc_parent(data, pid))
			return (1);
	}
	return (0);
}

int	init_heredoc(t_data *data, t_redirection *cur, t_command *cmd, int i)
{
	char	*name;

	name = ft_strjoin("/tmp/tmpz_", ft_itoa(i));
	cmd[i].fd[1] = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (cmd[i].fd[1] < 0)
	{
		print_error("heredoc file", "open");
		free(name);
		g_signal = 1;
		return (1);
	}
	if (execute_heredoc(cmd[i].fd[1], cur->file_name, data))
	{
		close(cmd[i].fd[1]);
		return (1);
	}
	close(cmd[i].fd[1]);
	cur->file_name = NULL;
	cur->file_name = name;
	return (0);
}

int	heredoc(t_data *data)
{
	int				i;
	t_command		*cmds;
	t_redirection	*current;

	i = 0;
	cmds = data->commands;
	while (i != data->cmd_nbr)
	{
		current = cmds[i].infile;
		while (current)
		{
			if (current->append == 2)
			{
				if (init_heredoc(data, current, cmds, i))
					return (1);
			}
			current = current->next;
		}
		i++;
	}
	return (0);
}
