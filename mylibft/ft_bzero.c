/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:39:41 by kmorin            #+#    #+#             */
/*   Updated: 2022/11/04 18:18:09 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mylibft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*s;
	size_t			i;

	s = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		s[i] = 0;
		i++;
	}
}
