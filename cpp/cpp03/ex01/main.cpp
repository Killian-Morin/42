/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:55:35 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 12:08:42 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void) {

	ScavTrap	bob("bob");
	ClapTrap	joe("joe");
	std::cout << std::endl;

	bob.attack("joe");
	joe.takeDamage(bob.getAttackDamage());

	bob.takeDamage(1);
	bob.beRepaired(1);

	// joe.attack("bob");

	// bob.guardGate();
	// bob.guardGate();

	// ScavTrap	empty;
	// empty.printStatus();

	// ScavTrap	duplicate(bob);
	// duplicate.printStatus();

	// ScavTrap	copy;
	// copy = bob;
	// copy.printStatus();

	return (0);
}
