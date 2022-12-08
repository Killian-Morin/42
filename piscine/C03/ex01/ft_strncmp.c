/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 10:10:48 by kmorin            #+#    #+#             */
/*   Updated: 2022/07/28 11:40:07 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < (n - 1) && s1[i] == s2[i] && s1[i])
	{
		i++;
	}
	if (n == 0)
	{
		return (0);
	}
	return (s1[i] - s2[i]);
}
/*
int	main(void)
{
	char	s1[] = "abc";
	char	s2[] = "abc";

	printf("avec ma fonction : %d \n", ft_strncmp(s1, s2, 4));
	printf("avec la fonction de base : %d \n", strncmp(s1, s2, 4));
}*/
