/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:58:06 by kmorin            #+#    #+#             */
/*   Updated: 2022/10/26 17:20:00 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i2;
	int					i;

	i = 0;
	i2 = 0;
	while (dest[i])
		i++;
	while (i2 != size)
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
	char	src[50] = "bonjour";
	char	dest[50] = "yeah";

	printf("%u\n", ft_strlcat(dest, src, 3));
	printf("%s\n", strlcat(dest, src, 3));
	return (0);
}*/
