/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:16:48 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/22 13:55:30 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int	N = 10;
	Zombie	*horde = zombieHorde(N, "Horde");

	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete [] horde;
	return (0);
}
