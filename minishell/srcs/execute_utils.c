/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:23:14 by killian           #+#    #+#             */
/*   Updated: 2023/10/24 09:41:20 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**get_paths(char **env)
{
	char	*path_line;
	char	**paths;

	path_line = get_variable_env(env, "PATH=");
	if (!path_line)
		return (NULL);
	paths = ft_split(path_line, ':');
	if (!paths)
		return (NULL);
	return (paths);
}

void	check_valid_path(char *path)
{
	DIR	*dir;

	dir = opendir(path);
	if (dir)
	{
		closedir(dir);
		exit_error("Is a directory", path, 126);
	}
	if (access(path, F_OK) != 0)
		exit_error(NULL, path, 127);
	if (access(path, R_OK & X_OK) != 0)
		exit_error(NULL, path, 126);
}

char	*create_path(char *path, char *cmd)
{
	char	*res;

	res = NULL;
	res = ft_strjoin(path, "/");
	res = ft_strjoin(res, cmd);
	return (res);
}

char	*check_all_paths(char **path, char *cmd)
{
	char	*cmd_path;
	int		j;

	j = 0;
	while (path[j])
	{
		cmd_path = create_path(path[j], cmd);
		if (access(cmd_path, F_OK) == 0)
		{
			check_valid_path(cmd_path);
			return (cmd_path);
		}
		free(cmd_path);
		j++;
	}
	return (NULL);
}

char	*get_path_for_command(t_data *data, int i)
{
	char	**all_path;
	char	*res;

	if (data->commands[i].full_cmd[0][0] == '\0')
		return (NULL);
	if (!ft_strncmp(data->commands[i].full_cmd[0], "/", 1)
		|| !ft_strncmp(data->commands[i].full_cmd[0], "./", 2))
	{
		check_valid_path(data->commands[i].full_cmd[0]);
		return (data->commands[i].full_cmd[0]);
	}
	all_path = get_paths(data->envp);
	if (!all_path)
	{
		check_valid_path(data->commands[i].full_cmd[0]);
		free_strs_table(all_path);
		res = ft_strdup(data->commands[i].full_cmd[0]);
		return (res);
	}
	else
	{
		res = check_all_paths(all_path, data->commands[i].full_cmd[0]);
		free_strs_table(all_path);
		return (res);
	}
}
