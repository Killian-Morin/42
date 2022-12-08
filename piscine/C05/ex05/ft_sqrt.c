/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:48:16 by kmorin            #+#    #+#             */
/*   Updated: 2022/08/02 16:28:05 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_sqrt(int nb)
{
	int	x;

	x = 0;
	if (nb < 0)
	{
		return (0);
	}
	if (nb > 0)
	{
		while (x * x != nb && x <= 46340)
		{
			x++;
		}
		if (x * x == nb)
		{
			return (x);
		}
		else
			return (0);
	}
	return (0);
}
/*
int	main(int argc, char **argv)
{
	int	str;

	if (argc == 2)
	{
		str = atoi(argv[1]);
		printf("%d\n", ft_sqrt(str));
	}
	else
		return (0);
}
*/
