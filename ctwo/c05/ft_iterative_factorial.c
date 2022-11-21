/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:29:52 by kmorin            #+#    #+#             */
/*   Updated: 2022/10/26 10:57:31 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	factor;

	factor = nb;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (factor != 1)
	{
		nb = nb * (factor - 1);
		factor--;
	}
	return (nb);
}

int	main(void)
{
	printf("%i\n", ft_iterative_factorial(7));
	return (0);
}
