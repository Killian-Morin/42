/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:49:24 by kmorin            #+#    #+#             */
/*   Updated: 2022/10/26 17:19:44 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	while (dest[i])
		i++;
	while (src[i2])
	{
		dest[i] = src[i2];
		i++;
		i2++;
	}
	dest[i] = '\0';
	return (dest);
}

int	main(void)
{
	char	src[50] = "salut";
	char	dest1[50] = "de meme";
	char	dest2[50] = "de meme";

	printf("%s\n", ft_strcat(dest1, src));
	printf("%s\n", strcat(dest2, src));
	return (0);
}
