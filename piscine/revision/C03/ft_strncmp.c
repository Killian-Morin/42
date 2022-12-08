/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:30:12 by kmorin            #+#    #+#             */
/*   Updated: 2022/08/04 09:39:10 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < (n - 1) && s1[i] && s1[i] == s2[i])
	{
		i++;
	}
	if (n == 0)
		return (0);
	return (s1[i] - s2[i]);
}

int	main(void)
{
	char	str1[15] = "aba";
	char	str2[15] = "abc";

	printf("%d\n", ft_strncmp(str1, str2, 3));
	printf("%d\n", strncmp(str1, str2, 3));
	return (0);
}
