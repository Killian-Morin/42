/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:02:08 by kmorin            #+#    #+#             */
/*   Updated: 2022/08/03 15:06:45 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_is_negative(int n)
{
	if (n < 0)
	{
		write(1, "N", 1);
	}
	else
		write(1, "P", 1);
}

int	main(int argc, char **argv)
{
	int	nb = 0;

	if (argc == 2 && argv[1])
	{
		nb = atoi(argv[1]);
		ft_is_negative(nb);
	}
	return (0);
}
