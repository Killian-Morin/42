/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:03:55 by kmorin            #+#    #+#             */
/*   Updated: 2022/10/26 11:38:36 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	a;

	a = nb;
	if (power < 0)
		return (0);
	if ((power == 0 && nb == 0) || power == 0)
		return (1);
	while (power > 1)
	{
		nb = nb * a;
		power--;
	}
	return (nb);
}

int	main(void)
{
	printf("%i\n", ft_iterative_power(4, 5));
	return (0);
}
