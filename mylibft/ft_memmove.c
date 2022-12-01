/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:12:56 by kmorin            #+#    #+#             */
/*   Updated: 2022/11/01 15:26:53 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mylibft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) dest;
	str2 = (unsigned char *) src;
	i = 0;
	if (dest == 0 && src == 0)
		return (0);
	if (dest > src)
	{
		while (i < n)
		{
			str1[n - i -1] = str2[n - i -1];
			i++;
		}
	}
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (dest);
}
