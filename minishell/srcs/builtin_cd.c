/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:45:03 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/24 09:40:58 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	update_env(t_data *data, char *var, char *new_value)
{
	int		var_index;
	char	*tmp;

	var_index = get_variable_index_env(data->envp, var);
	if (var_index != get_size_env(data->envp))
	{
		free(data->envp[var_index]);
		tmp = ft_strjoin(var, new_value);
		data->envp[var_index] = ft_strdup(tmp);
		free(tmp);
	}
}

void	ft_no_path(t_data *data)
{
	char	*home;
	char	cur_path[PATH_MAX];

	home = get_variable_env(data->envp, "HOME=");
	if (!home)
		return (print_error("HOME not set", "cd"));
	if (!getcwd(cur_path, PATH_MAX))
		return (print_error(NULL, "cd"));
	if (chdir(home) == -1)
		return (print_error(NULL, home));
	update_env(data, "OLDPWD=", cur_path);
	if (!getcwd(home, PATH_MAX))
		return (print_error(NULL, "cd"));
	update_env(data, "PWD=", home);
	free(home);
}

void	ft_to_oldpwd(t_data *data)
{
	char	*new_path;
	char	cur_path[PATH_MAX];

	new_path = get_variable_env(data->envp, "OLDPWD=");
	if (!new_path)
		return (print_error("OLDPWD not set", "cd"));
	if (!getcwd(cur_path, PATH_MAX))
		return (print_error(NULL, "cd"));
	if (chdir(new_path) == -1)
		return (print_error(NULL, new_path));
	update_env(data, "OLDPWD=", cur_path);
	if (!getcwd(cur_path, PATH_MAX))
		return (print_error(NULL, "cd"));
	update_env(data, "PWD=", cur_path);
	free(new_path);
	ft_pwd();
}

void	ft_path(t_data *data, char *directory)
{
	char	cur_path[PATH_MAX];

	if (!getcwd(cur_path, PATH_MAX))
		return (print_error(NULL, "cd"));
	if (chdir(directory) == -1)
		return (print_error(NULL, directory));
	update_env(data, "OLDPWD=", cur_path);
	if (!getcwd(cur_path, PATH_MAX))
		return (print_error(NULL, "cd"));
	update_env(data, "PWD=", cur_path);
}

int	ft_cd(t_data *data, char *directory)
{
	if (!directory)
		ft_no_path(data);
	else if (!ft_strncmp(directory, "-\0", 2))
		ft_to_oldpwd(data);
	else
		ft_path(data, directory);
	return (0);
}
