/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:49:33 by kmorin            #+#    #+#             */
/*   Updated: 2022/07/28 16:53:34 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int				i2;

	i = 0;
	i2 = 0;
	while (dest[i2] != '\0')
	{
		i2++;
	}
	while (i < nb && src[i] != '\0')
	{
		dest[i2] = src[i];
		i++;
		i2++;
	}
	dest[i2] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	src[10] = "source";
	char	dest[20] = "destination|";
	char	dest2[20] = "destination|";

	printf("fonction custom : [%s]\n", ft_strncat(dest, src, 20));
	printf("fonction de base : [%s]\n", strncat(dest2, src, 20));
}*/
