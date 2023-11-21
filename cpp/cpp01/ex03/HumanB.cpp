/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:38:27 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/21 11:53:29 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	this->_weapon = NULL;
}

HumanB::~HumanB()
{
	// std::cout << "HumanB destructor called" << std::endl;
}

void	HumanB::attack(void)
{
	if (this->_weapon != NULL && this->_weapon->getType() != "")
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << RED << this->_name << " does not have a weapon to use" << WHITE << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}
