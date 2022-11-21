/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:00:12 by kmorin            #+#    #+#             */
/*   Updated: 2022/10/26 12:43:08 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	x;

	x = 0;
	if (nb < 0)
		return (0);
	if (nb > 0)
	{
		while (x * x != nb && x <= 46340)
			x++;
		if (x * x == nb)
			return (x);
		else
			x++;
	}
	return (0);
}

int	main(void)
{
	printf("%i\n", ft_sqrt(2));
	return (0);
}
