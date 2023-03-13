/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:29:24 by kmorin            #+#    #+#             */
/*   Updated: 2022/11/01 13:29:49 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	cara;

	cara = (unsigned char) c;
	s = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (s[i] != cara)
			i++;
		else
			return ((void *)&s[i]);
	}
	return (0);
}
