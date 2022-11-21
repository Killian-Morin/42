/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:16:26 by kmorin            #+#    #+#             */
/*   Updated: 2022/10/26 13:26:58 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_find_next_prime(int nb)
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
			nb++;
	}
	return (nb);
}

int	main(void)
{
	printf("%i\n", ft_find_next_prime(14));
	return (0);
}
