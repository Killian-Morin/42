/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:55:35 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 12:20:08 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {

	FragTrap	bob("bob");
	std::cout << std::endl;

	bob.highFivesGuys();

	// bob.attack("moi");

	// ScavTrap	joe("joe");
	// std::cout << std::endl;

	// ClapTrap	abc("abc");
	// std::cout << std::endl;

	return (0);
}
