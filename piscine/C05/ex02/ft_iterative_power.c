/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:21:34 by kmorin            #+#    #+#             */
/*   Updated: 2022/08/01 10:31:30 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_iterative_power(int nb, int power)
{
	int	a;

	a = nb;
	if (power < 0)
	{
		return (0);
	}
	if ((power == 0 && nb == 0) || power == 0)
	{
		return (1);
	}
	while (power > 1)
	{
		nb = nb * a;
		power--;
	}
	return (nb);
}
/*
int	main(int argc, char *argv[])
{
	int	n;
	int	p;

	if (argc == 3 && argv[1] && argv[2])
	{
		n = atoi(argv[1]);
		p = atoi(argv[2]);
		printf("%i\n", ft_iterative_power(n, p));
	}
	return (0);
}*/
