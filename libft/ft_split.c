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

size_t	ft_countmot(char const *s, char c)
{
	size_t	i;
	size_t	nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] == c)
			nb++;
		i++;
	}
	nb = nb + 1;
	return (nb);
}

char	*ft_small(const char *s, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
		j++;
	return (ft_substr(s, i, j));
}

char	**ft_split(char const *s, char c)
{
	char	**bigstr;
	size_t	i;
	size_t	k;
	size_t	nbmot;

	if (s == NULL)
		return (NULL);
	nbmot = ft_countmot(s, c);
	bigstr = (char **)malloc(sizeof(char *) * (nbmot + 1));
	if (!bigstr)
		return (NULL);
	k = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
			i++;
		else
		{
			while (s[i + 1] == c || s[i + 1])
			{
				bigstr[k] = ft_small(s, i);
				i++;
			}
			k++;
		}
		i++;
	}
	bigstr[k + 1] = NULL;
	return (bigstr);
}
