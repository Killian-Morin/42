/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:35:19 by kmorin            #+#    #+#             */
/*   Updated: 2022/08/04 11:42:51 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_iterative_factorial(int nb)
{
	int	a;

	a = nb;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	if (nb == 1)
		return (nb);
	while (a > 1)
	{
		nb = nb * (a - 1);
		a--;
	}
	return (nb);
}

int	main(int argc, char **argv)
{
	int	nbr = 0;

	if (argc == 2 && argv[1])
	{
		nbr = atoi(argv[1]);
		printf("%d\n", ft_iterative_factorial(nbr));
	}
	return (0);
}
