/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:41:06 by kmorin            #+#    #+#             */
/*   Updated: 2022/10/25 09:58:37 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
			i++;
	return (s1[i] - s2[i]);
}

int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = "salu";
	s2 = "salu";
	printf("%i\n", ft_strcmp(s1, s2));
	printf("%i\n", strcmp(s1, s2));
	return (0);
}
