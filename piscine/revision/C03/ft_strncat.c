/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:53:58 by kmorin            #+#    #+#             */
/*   Updated: 2022/08/04 10:21:30 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int	i2;

	i = 0;
	i2 = 0;
	while (dest[i2])
		i2++;
	while (i < nb && src[i])
	{
		dest[i2] = src[i];
		i++;
		i2++;
	}
	dest[i2] = '\0';
	return (dest);
}

int	main(void)
{
	char	dest[15] = "yo";
	char	src[15] = "bonjour";
	char	dest1[15] = "yo";

	printf("%s\n", ft_strncat(dest, src, 10));
	printf("%s\n", strncat(dest1, src, 10));
	return (0);
	}
