/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:44:50 by kmorin            #+#    #+#             */
/*   Updated: 2022/07/26 12:16:02 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <string.h>
#include <stdio.h>
*/
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (*(src + i) != '\0' && i < n)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	while (i < n)
	{
		*(dest + i) = '\0';
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	src[15] = "salut";
	char	dest[15] = "yeah";

//	printf("avec strncpy la destination avant : %s \n \n", dest);
	printf("avec ft_strncpy la destination avant : %s \n \n", dest);
//	strncpy(dest, src, 0);
//	printf("avec strncpy la destination apres : %s \n \n", dest);	
	ft_strncpy(dest, src, 0);
	printf("avec ft_strncpy la destination apres : %s \n", dest);
	return (0);
}*/
