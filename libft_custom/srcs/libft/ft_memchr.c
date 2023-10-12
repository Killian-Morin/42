/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:29:24 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/12 15:24:01 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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
