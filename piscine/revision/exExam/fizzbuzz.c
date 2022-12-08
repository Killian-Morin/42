/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:53:16 by kmorin            #+#    #+#             */
/*   Updated: 2022/08/04 15:02:41 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	fizz_buzz(int nb)
{
	while (nb <= 100)
	{
		if (nb < 10)
		{
			if (nb % 3 == 0)
				write(1, "fizz", 4);
			else if (nb % 5 == 0)
				write(1, "buzz", 4);
			else if (nb % 5 == 0 && nb % 3 == 0)
				write(1, "fizzbuzz", 8);
			else
				ft_putchar(nb + 48);
			nb++;
			ft_putchar('\n');
		}
		if (nb > 10 && nb <= 100)
		{
			fizz_buzz(nb / 10);
			fizz_buzz(nb % 10);
		}
	}
}

int	main(void)
{
	int	nbr = 1;

	fizz_buzz(nbr);
	return (0);
}
