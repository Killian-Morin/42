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

int	ft_count(char const *s, char c, int len)
{
	int	nb;
	int	i;
	int	temp;

	i = 0;
	nb = 0;
	while (i < len)
	{
		while (i < len)
		{
			if (s[i] == c)
				break ;
			i++;
		}
		temp = i;
		while (i < len)
		{
			if (s[i] != c)
				break ;
			i++;
		}
		if (i > temp)
			nb++;
	}
	return (nb);
}

char	*ft_small(char const *s, char c, int len)
{
	int		i;
	int		k;
	int		temp;
	char	*smallstr;

	i = 0;
	k = 0;
	while (i < len)
	{
		while (i < len)
		{
			if (s[i] == c)
				break ;
			i++;
		}
		while (i < len)
		{
			if (s[i] != c)
				break ;
			i++;
			k++;
		}
		temp = i;
		i = 0;
		smallstr = malloc(sizeof(char *) * (k + 1));
		if (!smallstr)
			return (NULL);
		while (i != temp)
			smallstr[k++] = s[i++];
		smallstr[k] = '\0';
	}
	return (smallstr);
}

char	**ft_split(char const *s, char c)
{
	int		m;
	int		len;
	int		nbstr;
	char	**bigstr;

	len = ft_strlen(s);
	nbstr = ft_count(s, c, len);
	bigstr = (char **)malloc(sizeof(char *) * (nbstr + 1));
	if (!bigstr)
		return (NULL);
	m = 0;
	while (m != nbstr)
	{
		bigstr[m] = ft_small(s, c, len);
		m++;
	}
	bigstr[m] = NULL;
	return (bigstr);
}
