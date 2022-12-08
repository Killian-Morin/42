/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:39:26 by kmorin            #+#    #+#             */
/*   Updated: 2022/08/04 09:53:29 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	while (dest[i2])
		i2++;
	while (src[i])
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

	printf("%s\n", ft_strcat(dest, src));
	printf("%s\n", strcat(dest1, src));
	return (0);
}
