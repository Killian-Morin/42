/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkukaqi <bkukaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:53:55 by bkukaqi           #+#    #+#             */
/*   Updated: 2023/07/21 14:53:55 by bkukaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*create_token(char *content, t_token_type type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		exit_error(NULL, "malloc failed", EX_OSERR);
	token->next = NULL;
	token->type = type;
	token->content = content;
	return (token);
}

void	add_token(t_token **tokens, t_token *new)
{
	t_token	*current;

	current = *tokens;
	if (!current)
	{
		*tokens = new;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}

t_token_type	quote_type(char c)
{
	if (c == '"')
		return (DBL_QUOTE_STR);
	else if (c == '\'')
		return (QUOTE_STR);
	return (LITERAL);
}

int	number_of_commands(t_token *tok)
{
	int				i;
	t_token_type	tmp;

	i = 1;
	tmp = tok->type;
	while (tok)
	{
		if (tok->type == PIPE && tmp == PIPE)
			return (-1);
		if (tok->type == PIPE && tmp != PIPE)
			i++;
		if (tok->type != IGNORE)
			tmp = tok->type;
		tok = tok->next;
	}
	return (i);
}

/*
free all tokens and their contents from the struct
*/
void	clear_tokens(t_token *tok)
{
	t_token	*next;

	while (tok)
	{
		free(tok->content);
		next = tok->next;
		free(tok);
		tok = next;
	}
}
