/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_is.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:59:02 by killian           #+#    #+#             */
/*   Updated: 2023/10/24 09:41:49 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_quote(char c)
{
	if (c == '"' || c == '\'')
		return (1);
	return (0);
}

int	is_space(int c)
{
	if ((c == ' ' || (c >= 9 && c <= 13)))
		return (1);
	return (0);
}

int	is_sep(int c)
{
	if (c == '<' || c == '>' || c == '|' || is_space(c))
		return (1);
	return (0);
}

int	is_redir(t_token_type type)
{
	if (type == REDIR_OUT_APPEND || type == REDIR_IN || type == REDIR_OUT
		|| type == HERE_DOC)
		return (1);
	return (0);
}

int	is_string(t_token_type type)
{
	if (type == QUOTE_STR || type == DBL_QUOTE_STR || type == LITERAL)
		return (1);
	return (0);
}
