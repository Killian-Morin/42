/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:58:06 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/12 15:24:40 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	ls;

	j = 0;
	i = ft_strlen(dest);
	ls = ft_strlen(src);
	if (size == 0)
		return (ls);
	if (size - 1 < i)
		return (ls + size);
	if (size - 1 >= i)
	{
		while (src[j] && (i + j + 1) < size)
		{
			dest[i + j] = src[j];
			j++;
		}
	}
	dest[i + j] = '\0';
	return (i + ls);
}
