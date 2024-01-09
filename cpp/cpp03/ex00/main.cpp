/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:55:35 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 11:48:06 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {

	ClapTrap	bob("bob");
	ClapTrap	joe("joe");
	std::cout << std::endl;

	bob.attack("joe");
	joe.takeDamage(bob.getAttackDamage());

	// ClapTrap	rien;
	// std::cout << std::endl;

	// rien.attack("joe");
	// joe.takeDamage(10);

	// joe.beRepaired(2);

	// rien.setName("rien");

	// for (int i = 0; i < 10; i++)
	// 	rien.attack("joe");

	return (0);
}
