/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:21:22 by kmorin            #+#    #+#             */
/*   Updated: 2022/08/02 11:31:27 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_find_next_prime(int nb)
{
	int	x;

	x = 2;
	if (nb <= 1)
	{
		return (2);
	}
	else
	{
		while (x <= nb / x)
		{
			if (nb % x != 0 && x < nb)
			{
				x++;
			}
			else
				return (ft_find_next_prime(nb + 1));
		}
	}
	return (nb);
}
/*
int	main(int argc, char **argv)
{
	int	i;

	if (argc == 2 && argv[1])
	{
		i = atoi(argv[1]);
		printf("%d\n", ft_find_next_prime(i));
	}
	return (0);
}*/
