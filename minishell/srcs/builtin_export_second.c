/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_second.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:07:01 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/24 09:41:00 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
			i++;
	return (s1[i] - s2[i]);
}

char	**alpha_sort_tab(char **env)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (j < (get_size_env(env) - 1 - i))
		{
			if (ft_strcmp(env[j], env[j + 1]) > 0)
			{
				tmp = ft_strdup(env[j]);
				free(env[j]);
				env[j] = ft_strdup(env[j + 1]);
				free(env[j + 1]);
				env[j + 1] = ft_strdup(tmp);
				free(tmp);
			}
			j++;
		}
		i++;
	}
	return (env);
}

int	ft_export_no_arg(char **env)
{
	int		i;
	char	*value;
	char	*autre;

	env = alpha_sort_tab(env);
	i = 0;
	while (env[i])
	{
		value = ft_substr(env[i], 0, ft_strchr(env[i], '=') - env[i] + 1);
		printf("declare -x %s", value);
		if (ft_strchr(env[i], '='))
			printf("\"");
		autre = ft_substr(env[i],
				ft_strchr(env[i], '=') - env[i] + 1, ft_strlen(env[i]));
		printf("%s", autre);
		if (ft_strchr(env[i], '='))
			printf("\"");
		printf("\n");
		free(value);
		free(autre);
		i++;
	}
	return (0);
}
