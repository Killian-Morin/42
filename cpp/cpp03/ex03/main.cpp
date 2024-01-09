/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:55:35 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 12:36:10 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void) {

	DiamondTrap	empty;
	std::cout << std::endl;
	empty.whoAmI();
	// empty.attack("moi");
	// empty.beRepaired(1);
	// empty.takeDamage(1);

	// DiamondTrap	joe("joe");
	// std::cout << std::endl;
	// joe.whoAmI();

	// DiamondTrap	duplicate(joe);
	// std::cout << std::endl;
	// duplicate.whoAmI();

	// DiamondTrap	copy;
	// std::cout << std::endl;
	// copy = joe;
	// std::cout << std::endl;
	// copy.whoAmI();

	return (0);
}
