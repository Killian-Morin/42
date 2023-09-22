/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkukaqi <bkukaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:09:53 by bkukaqi           #+#    #+#             */
/*   Updated: 2023/07/20 16:09:53 by bkukaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	extract_literal(t_token **tokens, char *user_input)
{
	int				i;
	t_token_type	t;

	t = LITERAL;
	i = 0;
	while (user_input[i] && (!is_sep(user_input[i]) || t != LITERAL))
	{
		if (t == LITERAL && user_input[i] == '\'')
			t = QUOTE_STR;
		else if (t == LITERAL && user_input[i] == '"')
			t = DBL_QUOTE_STR;
		else if (t != LITERAL && quote_type(user_input[i]) == t)
			t = LITERAL;
		i++;
	}
	add_token(tokens, create_token(ft_substr(user_input, 0, i), t));
	return (i);
}

int	extract_quote_string(t_token **tokens, char *user_input)
{
	int				i;
	int				in_quote;
	t_token_type	t;

	in_quote = user_input[0];
	i = 1;
	while (user_input[i])
	{
		if (!in_quote && is_sep(user_input[i]))
			break ;
		if (is_quote(user_input[i]) && user_input[i] == in_quote)
			in_quote = 0;
		else if (is_quote(user_input[i]) && !in_quote)
			in_quote = user_input[i];
		i++;
	}
	if (user_input[0] == '"')
		t = DBL_QUOTE_STR;
	else
		t = QUOTE_STR;
	add_token(tokens, create_token(ft_substr(user_input, 0, i), t));
	return (i + 1);
}

int	extract_redir(t_token **tokens, char *user_input)
{
	if (user_input[0] == '<' && user_input[1] == '<')
	{
		add_token(tokens, create_token(ft_substr(user_input, 0, 2), HERE_DOC));
		return (2);
	}
	else if (user_input[0] == '<')
	{
		add_token(tokens, create_token(ft_substr(user_input, 0, 1), REDIR_IN));
		return (1);
	}
	else if (user_input[0] == '>' && user_input[1] == '>')
	{
		add_token(tokens, create_token(ft_substr(user_input, 0, 2),
				REDIR_OUT_APPEND));
		return (2);
	}
	else
	{
		add_token(tokens, create_token(ft_substr(user_input, 0, 1), REDIR_OUT));
		return (1);
	}
}

int	extract_tokens(t_token **tokens, char *user_input)
{
	int	i;

	i = 0;
	while (is_space(user_input[i]))
		i++;
	if (user_input[i] == '\0')
		return (i);
	else if (user_input[i] == '"' || user_input[i] == '\'')
		i += extract_quote_string(tokens, &user_input[i]);
	else if (user_input[i] == '|')
	{
		add_token(tokens, create_token(ft_substr(&user_input[i], 0, 1), PIPE));
		i++;
	}
	else if (user_input[i] == '<' || user_input[i] == '>')
		i += extract_redir(tokens, &user_input[i]);
	else
		i += extract_literal(tokens, &user_input[i]);
	return (i);
}

t_token	*tokenizer(char *input)
{
	size_t	i;
	t_token	*new;

	i = 0;
	new = NULL;
	if (!input)
		return (NULL);
	while (i < ft_strlen(input))
		i += extract_tokens(&new, &input[i]);
	return (new);
}
