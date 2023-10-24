/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_variable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:57:16 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/24 09:41:27 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_variable_env_expansion(char **env, char *var)
{
	char	*tmp;
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], var, ft_strlen(var)))
		{
			tmp = ft_substr(env[i], ft_strchr_index(env[i], '=') + 1,
					ft_strlen(env[i]));
			return (tmp);
		}
		i++;
	}
	return (NULL);
}

int	get_end_env_var(char *str, int in_quote)
{
	int	i;

	i = 0;
	if (str[i] == '?')
		return (1);
	else if ((in_quote && str[i] == in_quote) || ft_isdigit(str[i]))
		return (0);
	else if (!in_quote && is_quote(str[i]))
		return (-1);
	while (ft_isalpha(str[i]))
		i++;
	return (i);
}

char	*get_env_var(char **env, char *str, int end)
{
	char	*var;

	if (end == 0)
		return (NULL);
	if (end == -1)
		var = ft_strdup("");
	else
		var = ft_substr(str, 0, end);
	if (!ft_strncmp(var, "?", 1))
		var = ft_itoa(g_signal);
	else
	{
		var = ft_strjoin(var, "=");
		var = get_variable_env_expansion(env, var);
	}
	if (!var)
		var = ft_strdup("");
	return (var);
}

int	expand_env_var(char **env, char **str, int pos, int in_quote)
{
	int		end;
	int		size;
	char	*var;
	char	*new;

	end = get_end_env_var(&(*str)[pos], in_quote);
	var = get_env_var(env, &(*str)[pos], end);
	if (end == -1)
		end = 0;
	if (end == 0 && !var)
		return (1);
	end += pos;
	size = ft_strlen(*str) - (end - pos) + ft_strlen(var) + 1;
	new = ft_calloc(sizeof(char), size + 1);
	if (!new)
		exit_error(NULL, "malloc", EX_OSERR);
	ft_strlcat(new, *str, pos);
	ft_strlcat(new, var, ft_strlen(new) + ft_strlen(var) + 1);
	ft_strlcat(new, &(*str)[end], size);
	end = ft_strlen(var);
	free(var);
	free(*str);
	*str = new;
	return (end);
}
