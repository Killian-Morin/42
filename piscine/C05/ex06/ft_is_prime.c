/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:44:02 by kmorin            #+#    #+#             */
/*   Updated: 2022/08/02 08:40:04 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_is_prime(int nb)
{
	int	x;

	x = 2;
	if (nb <= 1)
	{
		return (0);
	}
	while (x <= nb / x)
	{	
		if (nb % x != 0 && x < nb)
		{
			x++;
		}
		else
			return (0);
	}
	return (1);
}
/*
int	main(int argc, char **argv)
{
	int	str;

	if (argc == 2 && argv[1])
	{
		str = atoi(argv[1]);
		printf("%d\n", ft_is_prime(str));
	}
	else
		return (0);
}*/
