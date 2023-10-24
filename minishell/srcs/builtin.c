/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:53:43 by killian           #+#    #+#             */
/*   Updated: 2023/10/24 09:41:05 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_a_builtin(char **cmd)
{
	if (cmd && !cmd[0])
		return (0);
	if (!ft_strncmp(cmd[0], "echo\0", 5)
		|| (!ft_strncmp(cmd[0], "cd\0", 3))
		|| (!ft_strncmp(cmd[0], "pwd\0", 4))
		|| (!ft_strncmp(cmd[0], "export\0", 7))
		|| (!ft_strncmp(cmd[0], "unset\0", 6))
		|| (!ft_strncmp(cmd[0], "env\0", 4))
		|| (!ft_strncmp(cmd[0], "exit\0", 5)))
		return (1);
	return (0);
}

int	which_builtin(t_data *data, int i)
{
	if (!ft_strncmp(data->commands[i].full_cmd[0], "echo\0", 5))
		return (ft_echo(data->commands[i].full_cmd));
	else if (!ft_strncmp(data->commands[i].full_cmd[0], "cd\0", 3))
		return (ft_cd(data, data->commands[i].full_cmd[1]));
	else if (!ft_strncmp(data->commands[i].full_cmd[0], "pwd\0", 4))
		return (ft_pwd());
	else if (!ft_strncmp(data->commands[i].full_cmd[0], "export\0", 7)
		&& !data->commands[i].full_cmd[1])
		return (ft_export_no_arg(data->envp));
	else if (!ft_strncmp(data->commands[i].full_cmd[0], "export\0", 7))
		return (ft_export(data, data->commands[i].full_cmd[1]));
	else if (!ft_strncmp(data->commands[i].full_cmd[0], "unset\0", 6))
		return (ft_unset(data, i));
	else if (!ft_strncmp(data->commands[i].full_cmd[0], "env\0", 4))
		return (ft_env(data->envp));
	else if (!ft_strncmp(data->commands[i].full_cmd[0], "exit\0", 5))
		return (ft_exit(data, i));
	return (0);
}

void	restore_redirections_builtin(t_data *data)
{
	dup2(data->previous_fd[0], STDIN_FILENO);
	close(data->previous_fd[0]);
	dup2(data->previous_fd[1], STDOUT_FILENO);
	close(data->previous_fd[1]);
}

int	exec_one_builtin(t_data *data)
{
	data->previous_fd[0] = dup(STDIN_FILENO);
	data->previous_fd[1] = dup(STDOUT_FILENO);
	if (in_redirection(&data->commands[0]))
	{
		close_redirections(&data->commands[0]);
		return (1);
	}
	if (out_redirection(&data->commands[0]))
	{
		close_redirections(&data->commands[0]);
		return (1);
	}
	if (which_builtin(data, 0))
		g_signal = 1;
	close_redirections(&data->commands[0]);
	restore_redirections_builtin(data);
	return (0);
}
