/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:55:35 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/30 15:42:41 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	empty;
	std::cout << std::endl;
	empty.whoAmI();
	empty.attack("moi");

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
