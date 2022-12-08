/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:12:08 by kmorin            #+#    #+#             */
/*   Updated: 2022/08/03 18:17:47 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i + 1] = '\0';
		i++;
	}
	return (dest);
}

int	main(void)
{
	char	dest[15] = "hey";
	char	src[15] = "hello there";

	printf("%s\n", ft_strncpy(dest, src, 0));
	return (0);
}
