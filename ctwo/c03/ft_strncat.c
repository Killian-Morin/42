/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:00:59 by kmorin            #+#    #+#             */
/*   Updated: 2022/10/26 17:21:12 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i2;
	int	i;

	i = 0;
	i2 = 0;
	while (dest[i])
		i++;
	while (i2 != nb)
	{
		dest[i] = src[i2];
		i2++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	src[50] = "de meme";
	char	dest[50] = "salut";

	printf("%s\n", ft_strncat(dest, src, 10));
	printf("%s\n", strncat(dest, src, 10));
	return (0);
}*/
