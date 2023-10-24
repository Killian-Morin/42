/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:04:03 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/24 09:41:29 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_for_quotes(char **env, char **str)
{
	int	i;
	int	j;
	int	in_quote;

	i = 0;
	in_quote = 0;
	while ((*str)[i])
	{
		if (in_quote == (*str)[i] && is_quote((*str)[i]))
			in_quote = 0;
		if (!in_quote && is_quote((*str)[i]))
			in_quote = (*str)[i];
		else if (in_quote != '\'' && (*str)[i] == '$')
		{
			j = expand_env_var(env, str, i + 1, in_quote);
			i += j - 1;
		}
		i++;
	}
}

char	*expansion_tilde_home(char *str, char **env)
{
	char	*home;
	char	*tmp;

	home = get_variable_env(env, "HOME=");
	if (!home)
		ft_strdup("");
	tmp = ft_strjoin(home, str + 1);
	free(home);
	free(str);
	return (tmp);
}

t_token	*expansion(t_token *tok, char **env)
{
	if (!ft_strncmp(tok->content, "~", 1) || !ft_strncmp(tok->content, "~/", 2))
		tok->content = expansion_tilde_home(tok->content, env);
	else
		check_for_quotes(env, &tok->content);
	if (tok->content[0] == '\0')
	{
		tok->type = IGNORE;
		return (tok);
	}
	tok->content = delete_quotes(tok->content);
	if (!tok->content)
		return (NULL);
	return (tok);
}

int	expansion_manager(t_token *tok, char **env)
{
	int	heredoc;

	heredoc = 0;
	while (tok)
	{
		if (tok->type == HERE_DOC)
			heredoc = 1;
		if (is_string(tok->type) && !heredoc)
		{
			tok = expansion(tok, env);
			if (!tok)
			{
				g_signal = 2;
				return (1);
			}
		}
		else if (heredoc && tok->type != HERE_DOC)
			heredoc = 0;
		tok = tok->next;
	}
	return (0);
}
