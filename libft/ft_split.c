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

size_t	ft_countsep(char const *s, char c)
{
	size_t		i;
	size_t		nbsep;

	i = 0;
	nbsep = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			nbsep++;
			i++;
		}
		else
			i++;
	}
	return (nbsep);
}

char	*ft_small(char const *s, char c)
{
	char	*smallstr;
	size_t	i;
	size_t	j;
	size_t	l;

	i = 0;
	j = 0;
	while (s[i + j] != '\0' && s[i + j] != c)
		j++;
	smallstr = (char *)malloc(sizeof(smallstr) * (j + 1));
	if (!smallstr)
		return (NULL);
	l = 0;
	while (l < j)
	{
		smallstr[l] = s[i];
		i++;
		l++;
	}
	smallstr[l] = '\0';
	return (smallstr);
}

char	**ft_split(char const *s, char c)
{
	char	**bigstr;
	char	*smallstr;
	size_t	i;
	size_t	k;
	size_t	z;

	if (s == NULL)
		return (NULL);
	bigstr = (char **)malloc(sizeof(bigstr) * (ft_countsep(s, c) + 1));
	if (!bigstr)
		return (NULL);
	i = 0;
	k = 0;
	while (k != ft_countsep(s, c) && s[i])
	{
		z = 0;
		if (s[i] != c)
		{
			while (s[i + z] != c)
			{
				smallstr = ft_small(s, c);
				i++;
				z++;
			}
		}
		else
			i++;
			bigstr[k] = smallstr;
			k++;
	}
	bigstr[k] = NULL;
	return (bigstr);
}
