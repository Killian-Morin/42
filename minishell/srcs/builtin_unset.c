/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:47:21 by killian           #+#    #+#             */
/*   Updated: 2023/10/24 09:41:04 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_adjust_unset(t_data *data, int index_var)
{
	int		j;
	char	**env;

	env = malloc(sizeof(env) * get_size_env(data->envp));
	if (!env)
	{
		exit_error(NULL, "malloc failed", EX_OSERR);
		return (NULL);
	}
	j = 0;
	while (j < index_var)
	{
		env[j] = ft_strdup(data->envp[j]);
		j++;
	}
	while (j < get_size_env(data->envp) - 1)
	{
		env[j] = ft_strdup(data->envp[j + 1]);
		j++;
	}
	env[j] = NULL;
	free_strs_table(data->envp);
	return (env);
}

int	ft_unset(t_data *data, int i)
{
	int		res;
	int		j;

	j = 1;
	while (data->commands[i].full_cmd[j])
	{
		res = get_variable_index_env(data->envp, data->commands[i].full_cmd[j]);
		if (res == get_size_env(data->envp))
			return (1);
		data->envp = ft_adjust_unset(data, res);
		if (!data->envp)
			return (1);
		j++;
	}
	return (0);
}
