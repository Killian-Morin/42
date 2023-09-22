/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkukaqi <bkukaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:59:26 by bkukaqi           #+#    #+#             */
/*   Updated: 2023/07/21 15:59:26 by bkukaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	children(t_data *data, int i)
{
	if (is_a_builtin(data->commands[i].full_cmd))
		which_builtin(data, i);
	else
	{
		if (!data->commands[i].full_cmd[0])
			exit(0);
		data->commands[i].path = get_path_for_command(data, i);
		if (!data->commands[i].path)
			exit_error("command not found", data->commands[i].full_cmd[0], 127);
		enable_print_termios();
		execve(data->commands[i].path, data->commands[i].full_cmd, data->envp);
	}
	exit(g_signal);
}

void	do_for_each_cmd(t_data *data, int i)
{
	g_signal = -1;
	if (pipe(data->commands[i].fd) == -1)
		exit_error("pipe", "pipe failed", EX_OSERR);
	data->commands[i].pid = fork();
	if (data->commands[i].pid == -1)
		exit_error("fork", "fork failed", EX_OSERR);
	else if (data->commands[i].pid == 0)
	{
		ft_redirection_pipe(data, i);
		if (data->commands[i].infile)
		{
			if (in_redirection(&data->commands[i]))
				exit(EXIT_FAILURE);
		}
		if (data->commands[i].outfile)
		{
			if (out_redirection(&data->commands[i]))
				exit(EXIT_FAILURE);
		}
		close_all_pipes(data, i);
		children(data, i);
	}
}

void	exec_loop(t_data *data)
{
	int	i;
	int	status;

	i = 0;
	while (i < data->cmd_nbr)
	{
		do_for_each_cmd(data, i);
		i++;
	}
	close_all_pipes(data, i - 1);
	i = 0;
	while (i < data->cmd_nbr)
	{
		waitpid(data->commands[i].pid, &status, 0);
		i++;
	}
	i = 0;
	while (i < data->cmd_nbr)
	{
		unlink_heredoc(data, i);
		i++;
	}
	check_status(status);
	disable_print_termios();
}

int	execute(t_data *data)
{
	if (heredoc(data))
		return (0);
	if (data->cmd_nbr == 1 && is_a_builtin(data->commands[0].full_cmd))
		return (exec_one_builtin(data));
	else
		exec_loop(data);
	return (0);
}
