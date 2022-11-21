/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:43:28 by kmorin            #+#    #+#             */
/*   Updated: 2022/10/26 16:00:30 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	x;

	x = 2;
	if (nb <= 1)
		return (0);
	while (x <= nb / x)
	{
		if (nb % x != 0 && x < nb)
			x++;
		else
			return (0);
	}
	return (1);
}

int	main(void)
{
	printf("%i\n", ft_is_prime(4));
	return (0);
}
