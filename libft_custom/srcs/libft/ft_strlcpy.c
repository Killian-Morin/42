/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:45:41 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/12 15:24:43 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;

	i = 0;
	if (destsize == 0)
		return (ft_strlen(src));
	if (destsize <= ft_strlen(src))
	{
		while (i < (destsize - 1))
		{
			dest[i] = src[i];
			i++;
		}
	}
	if (destsize > ft_strlen(src))
	{
		while (src[i])
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
