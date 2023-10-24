/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:59:03 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/24 09:41:25 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	get_quotes_nb(char *s)
{
	int	i;
	int	nb;
	int	in_quote;

	i = 0;
	nb = 0;
	in_quote = 0;
	while (s[i])
	{
		if (is_quote(s[i]))
		{
			if (!in_quote)
			{
				in_quote = s[i];
				nb++;
			}
			else if (in_quote == s[i])
			{
				in_quote = 0;
				nb++;
			}
		}
		i++;
	}
	return (nb);
}

int	check_valid_quotes(char *s)
{
	int	i;
	int	in_quote;

	i = 0;
	in_quote = 0;
	while (s[i])
	{
		if (is_quote(s[i]) && !in_quote)
			in_quote = s[i];
		else if (is_quote(s[i]) && in_quote == s[i])
			in_quote = 0;
		i++;
	}
	if (in_quote)
		return (1);
	return (0);
}

char	*deletion_of_quotes(char *s, char *new)
{
	int	i;
	int	j;
	int	in_quote;

	i = 0;
	j = 0;
	in_quote = 0;
	while (s[i])
	{
		if (!is_quote(s[i]) || (is_quote(s[i]) && in_quote && in_quote != s[i]))
			new[j++] = s[i];
		else if (!in_quote)
			in_quote = s[i];
		else if (is_quote(s[i]) && in_quote == s[i])
			in_quote = 0;
		i++;
	}
	free(s);
	new[j] = '\0';
	return (new);
}

char	*delete_quotes(char *s)
{
	int		nb_quotes;
	char	*new;

	if (check_valid_quotes(s))
	{
		free(s);
		return (NULL);
	}
	nb_quotes = get_quotes_nb(s);
	if (nb_quotes == 0)
		return (s);
	new = malloc(sizeof(new) * ft_strlen(s) - nb_quotes + 1);
	if (!new)
		exit_error(NULL, "malloc failed", EX_OSERR);
	new = deletion_of_quotes(s, new);
	return (new);
}
