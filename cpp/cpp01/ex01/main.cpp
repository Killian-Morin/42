/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:16:48 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 09:18:11 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {

	int	N = 10;
	Zombie	*horde = zombieHorde(N, "Horde");

	std::cout << std::endl;

	for (int i = 0; i < N; i++)
		horde[i].announce();

	std::cout << std::endl;

	delete [] horde;

	return (0);
}
