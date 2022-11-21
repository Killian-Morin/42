/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:59:00 by kmorin            #+#    #+#             */
/*   Updated: 2022/10/25 10:49:04 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < (n - 1) && s1[i] && s1[i] == s2[i])
		i++;
	if (n == 0)
		return (0);
	return (s1[i] - s2[i]);
}

int	main(void)
{
	char	*s1;
	char	*s2;
	unsigned int	n;

	s1 = "salut";
	s2 = "saluf";
	n = 4;
	printf("%i\n", ft_strncmp(s1, s2, n));
	printf("%i\n", strncmp(s1, s2, n));
	return (0);
}
