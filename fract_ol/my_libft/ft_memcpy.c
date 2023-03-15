/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:59:44 by kmorin            #+#    #+#             */
/*   Updated: 2022/11/01 11:48:52 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) dest;
	str2 = (unsigned char *) src;
	i = 0;
	if (dest == 0 && src == 0)
		return (0);
	while (n > 0)
	{
		str1[i] = str2[i];
		i++;
		n--;
	}
	return (str1);
}
