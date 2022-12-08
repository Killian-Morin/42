/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:12:57 by kmorin            #+#    #+#             */
/*   Updated: 2022/08/01 10:34:12 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
	{
		return (0);
	}
	if ((power == 0 && nb == 0) || power == 0)
	{
		return (1);
	}
	if (power > 1)
	{
		return (nb * ft_recursive_power(nb, power - 1));
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
		printf("%i\n", ft_recursive_power(n, p));
	}
	return (0);
}*/
