/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:11:27 by kmorin            #+#    #+#             */
/*   Updated: 2022/11/02 14:56:06 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nb, size_t len)
{
	unsigned char	*str;

	str = malloc(nb * len);
	if (!str)
		return (NULL);
	ft_bzero(str, nb * len);
	return (str);
}
