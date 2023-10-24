/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:50:57 by killian           #+#    #+#             */
/*   Updated: 2023/10/24 09:41:31 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	child_loop(int fd, int expand, char *delimiter, t_data *data)
{
	char	*line;

	line = "";
	while (line)
	{
		line = readline("> ");
		if (!line)
			return ;
		if (!ft_strncmp(delimiter, line, ft_strlen(delimiter) + 1))
		{
			free(line);
			break ;
		}
		if (!expand)
			check_for_quotes(data->envp, &line);
		if (line)
		{
			ft_putstr_fd(line, fd);
			ft_putchar_fd('\n', fd);
			free(line);
		}
	}
}

void	heredoc_child(int fd, int expand, char *delimiter, t_data *data)
{
	restore_sig(data);
	heredoc_signal();
	child_loop(fd, expand, delimiter, data);
	exit(0);
}

int	heredoc_parent(t_data *data, pid_t pid)
{
	int	status;

	ignore_sig();
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_signal = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
	{
		manage_sig(data);
		g_signal = 1;
		return (1);
	}
	manage_sig(data);
	return (0);
}

/*
when in the heredoc the ^C ^D ^\ behaviour goes back to the default ones
^C new line and new prompt
^D only a new prompt without clearing the line
^\ does nothing
*/
void	heredoc_signal(void)
{
	struct sigaction	sig;

	ft_bzero(&sig, sizeof(struct sigaction));
	sig.sa_handler = SIG_DFL;
	if (sigaction(SIGINT, &sig, NULL) == -1)
		printf("sigint error");
	sig.sa_handler = SIG_IGN;
	if (sigaction(SIGQUIT, &sig, NULL) == -1)
		printf("sigquit error");
}

void	unlink_heredoc(t_data *data, int i)
{
	t_redirection	*cur;

	cur = data->commands[i].infile;
	while (cur && cur->next)
		cur = cur->next;
	if (cur)
	{
		if (cur->append == 2)
		{
			if (unlink(cur->file_name) == -1)
				print_error("deleting heredoc", "unlink");
		}
	}
}
