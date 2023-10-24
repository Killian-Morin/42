/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:46:12 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/24 09:38:41 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countmot_path(char *src, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 1;
	while (src[i])
	{
		if (src[i] != c)
		{
			nb++;
			while (src[i] != c && src[i])
				i++;
		}
		else
			i++;
	}
	return (nb);
}

int	*ft_cara_par_str_path(char *src, char c, int nbmot)
{
	int	i;
	int	len;
	int	*lenstr;

	i = 0;
	lenstr = malloc(sizeof(int) * nbmot);
	if (!lenstr)
		return (NULL);
	while (*src)
	{
		if (*src != c)
		{
			len = 0;
			while (*src != c && *src)
			{
				src++;
				len++;
			}
			lenstr[i++] = len + 1;
		}
		else
			src++;
	}
	return (lenstr);
}

char	**ft_free_path(char **bigstr, int i, int *len)
{
	int	k;

	k = 0;
	while (i > k)
		free(bigstr[k++]);
	free(bigstr);
	free(len);
	return (NULL);
}

char	**ft_fill_tab_path(char *src, char c, char **bigstr, int *len)
{
	int	j;
	int	k;

	k = 0;
	while (*src)
	{
		if (*src != c)
		{
			bigstr[k] = malloc(sizeof(char) * len[k] + 1);
			if (!bigstr[k])
				return (ft_free_path(bigstr, k, len));
			j = 0;
			while (*src != c && *src)
				bigstr[k][j++] = *src++;
			bigstr[k][j++] = '/';
			bigstr[k++][j] = '\0';
		}
		else
			src++;
	}
	bigstr[k] = NULL;
	free(len);
	return (bigstr);
}

char	**ft_split_path(char const *s, char c)
{
	int		nbmot;
	int		*carastrnb;
	char	*src;
	char	**bigstr;

	src = (char *)s;
	nbmot = ft_countmot_path(src, c);
	carastrnb = ft_cara_par_str_path(src, c, nbmot);
	bigstr = malloc(sizeof(char *) * nbmot);
	if (!bigstr)
	{
		free(carastrnb);
		return (NULL);
	}
	return (ft_fill_tab_path(src, c, bigstr, carastrnb));
}
