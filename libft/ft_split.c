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

int	ft_countmot(char const *s, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] == c)
			nb++;
		i++;
	}
	printf("%i\n", nb);
	return (nb);
}

char	*ft_small(char const *s, char c)
{
	char	*smallstr;
	int		i;
	int		j;
	int		l;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
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
	int		i;
	int		k;
	int		nbmot;

	if (s == NULL)
		return (NULL);
	nbmot = ft_countmot(s, c);
	bigstr = malloc(sizeof(char *) * (nbmot + 1));
	if (!bigstr)
		return (NULL);
	i = 0;
	k = 0;
	while (k < nbmot)
	{
		while (s[i] != c)
		{
			smallstr = ft_small(s, c);
			printf("%s\n", smallstr);
			i++;
		}
		if (s[i] == c)
		{
			bigstr[k] = smallstr;
			k++;
			i++;
		}
	}
	bigstr[k] = NULL;
	return (bigstr);
}
