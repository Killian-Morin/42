/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 09:53:15 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/24 09:41:02 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	ft_strchr_index(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(str))
	{
		if (str[i] == (char)c)
			return (i);
		else
			i++;
	}
	return (i);
}

char	**ft_new_export(t_data *data, char *var_name, char *new_value)
{
	char	**env;
	char	*new;
	int		j;

	env = malloc(sizeof(char *) * (get_size_env(data->envp) + 2));
	if (!env)
	{
		exit_error(NULL, "malloc failed", EX_OSERR);
		return (NULL);
	}
	j = 0;
	while (j != get_size_env(data->envp))
	{
		env[j] = ft_strdup(data->envp[j]);
		j++;
	}
	new = NULL;
	new = ft_strjoin(var_name, new_value);
	env[j++] = ft_strdup(new);
	env[j] = NULL;
	free_strs_table(data->envp);
	free(new);
	return (env);
}

int	ft_export(t_data *data, char *cmd)
{
	char	*var_name;
	char	*new_value;
	int		var_index;

	var_name = ft_substr(cmd, 0, ft_strchr_index(cmd, '='));
	new_value = ft_substr(cmd, ft_strchr_index(cmd, '='), ft_strlen(cmd));
	var_index = get_variable_index_env(data->envp, var_name);
	if (var_index == get_size_env(data->envp))
	{
		data->envp = ft_new_export(data, var_name, new_value);
		free(var_name);
		free(new_value);
		if (!data->envp)
			return (1);
		return (0);
	}
	else
	{
		free(data->envp[var_index]);
		data->envp[var_index] = ft_strjoin(var_name, new_value);
		free(var_name);
		free(new_value);
	}
	return (0);
}
