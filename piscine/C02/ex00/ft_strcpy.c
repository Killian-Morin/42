/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:12:44 by kmorin            #+#    #+#             */
/*   Updated: 2022/07/25 13:32:50 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <string.h>
#include <stdio.h>
*/
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	str1[15] = "hello";
	char	str2[15] = "hey hey";

//	printf("avec strcpy la destination avant : %s \n \n", str2);
	printf("avec ft_strcpy la destination avant : %s \n \n", str2);
//	strcpy(str2, str1);
//	printf("avec strcpy la destination apres : %s \n \n", str2);
	ft_strcpy(str2, str1);
	printf("avec ft_strcpy la destination apres : %s \n", str2);
	return (0);
}*/
