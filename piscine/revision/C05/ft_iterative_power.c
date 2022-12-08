/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:48:21 by kmorin            #+#    #+#             */
/*   Updated: 2022/08/04 11:54:07 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_iterative_power(int nb, int power)
{
	int	a;

	a = nb;
	if ((nb == 0 && power == 0) || power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (power > 1)
	{
		nb = nb * a;
		power--;
	}
	return (nb);
}

int	main(int argc, char **argv)
{
	int	a = 0;
	int	b = 0;

	if (argc == 3 && argv[1] && argv[2])
	{
		a = atoi(argv[1]);
		b = atoi(argv[2]);
		printf("%d\n", ft_iterative_power(a, b));
	}
	return (0);
}
