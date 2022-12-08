/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 08:55:53 by kmorin            #+#    #+#             */
/*   Updated: 2022/08/03 09:24:39 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	if (min >= max)
	{
		return ('\0');
	}
	else
		i = max - min;
		a = malloc(sizeof(int) * i);
		while (a < max)
		{
			return (&a);
			a++;
		}
	return (0);
}

int	main(int argc, char **argv)
{
	int	bas;
	int	haut;

	if (argc == 3 && argv[1] && argv[2])
	{
		bas = atoi(argv[1]);
		haut = atoi(argv[2]);
		printf("%s\n", ft_range(bas, haut));
	}
	return (0);
}
