/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:47:00 by kmorin            #+#    #+#             */
/*   Updated: 2022/08/04 12:53:47 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	x;

	x = 0;
	if (nb < 0)
		return (0);
	if (nb > 0)
	{
		while (x * x != nb && x < 43640)
		{
			x++;
		}
		if (x * x == nb)
			return (x);
		else 
			return (0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	a = 0;

	if (argc == 2 && argv[1])
	{
		a = atoi(argv[1]);
		printf("%d\n", ft_sqrt(a));
	}
	return (0);
}
