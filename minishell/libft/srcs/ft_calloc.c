/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:11:27 by kmorin            #+#    #+#             */
/*   Updated: 2023/09/07 11:21:09 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t nb, size_t len)
{
	unsigned char	*str;

	str = malloc(nb * len);
	if (!str)
		return (NULL);
	ft_bzero(str, nb * len);
	return (str);
}
