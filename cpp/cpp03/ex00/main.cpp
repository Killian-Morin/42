/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:55:35 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/01 13:10:14 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
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

	// rien.attack("joe");
	// rien.attack("joe");
	// rien.attack("joe");
	// rien.attack("joe");
	// rien.attack("joe");
	// rien.attack("joe");
	// rien.attack("joe");
	// rien.attack("joe");
	// rien.attack("joe");
	// rien.attack("joe");

	return (0);
}
