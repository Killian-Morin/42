/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:03:49 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 09:05:34 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {

	Zombie	*tmp = newZombie("Allocated");

	std::cout << std::endl;

	tmp->announce();

	std::cout << std::endl;

	randomChump("random");

	std::cout << std::endl;

	delete tmp;

	return (0);
}
