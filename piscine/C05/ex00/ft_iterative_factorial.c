/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:27:04 by kmorin            #+#    #+#             */
/*   Updated: 2022/08/01 10:23:05 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_iterative_factorial(int nb)
{
	int	a;

	a = nb;
	if (nb < 0)
	{
		return (0);
	}
	if (nb == 0)
	{
		return (1);
	}
	while (a > 1)
	{
		nb = nb * (a - 1);
		a--;
	}
	return (nb);
}
/*
int	main(int argc, char *argv[])
{
	int	i;

	if (argc == 2 && argv[1])
	{
		i = atoi(argv[1]);
		printf("%i\n", ft_iterative_factorial(i));
	}
	return (0);
}*/
