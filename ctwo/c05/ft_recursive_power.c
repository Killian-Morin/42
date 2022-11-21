/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:21:27 by kmorin            #+#    #+#             */
/*   Updated: 2022/10/26 11:37:29 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	int	a;

	a = nb;
	if (power < 0)
		return (0);
	if ((power == 0 && nb == 0) || power == 0)
		return (1);
	if (power > 1)
		nb = nb * ft_recursive_power(a, (power - 1));
	return (nb);
}

int	main(void)
{
	printf("%i\n", ft_recursive_power(5, 2));
	return (0);
}
