/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:38:14 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/22 14:04:09 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA()
{
	// std::cout << "HumanA destructor called" << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << GREEN << this->_name << " attacks with their " << this->_weapon.getType() << WHITE << std::endl;
}
