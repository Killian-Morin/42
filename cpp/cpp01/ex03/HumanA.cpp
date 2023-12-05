/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:38:14 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/05 15:34:35 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA(void)
{
	// std::cout << COLOR("HumanA Default destructor called", RED) << WHITE << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << GREEN << this->_name << " attacks with their " << this->_weapon.getType() << WHITE << std::endl;
}
