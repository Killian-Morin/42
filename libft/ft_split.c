/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:46:12 by kmorin            #+#    #+#             */
/*   Updated: 2022/11/10 14:00:14 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbsep(char const *s)
{
	int		i;
	size_t	nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] == ' ')
		{
			nb++;
			i++;
		}
		else
			i++;
	}
	return (nb);
}

char	**ft_split(char const *s, char c)
{
	char		**str;
	size_t		nbsep;
	size_t		nbmot;
	size_t		i;
	size_t		j;

	nbsep = ft_nbsep(s);
	nbmot = nbsep + 1;
	str = malloc(sizeof(*s) * nbmot);
	if (!str)
		return (NULL);
	i = 0;
	while (i != ft_strlen(s))
	{
		if (s[i] == ' ')
		{
			s[i] = c;
			i++;
		}
		else
			i++;
	}
	j = 0;
	while (s[i] && j <= nbmot)
	{
		if (s[i] == c)
		{
			str[j][i] = c;
			j++;
			i = 0;
		}
		else
		{
			str[j][i] = s[i];
		}
		i++;
	}
	return (str);
}
