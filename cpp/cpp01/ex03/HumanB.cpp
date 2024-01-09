/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:38:27 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 10:36:13 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/* ************************************************************************** */
/*                      PARAMETRIC CONSTRUCTOR/DESTRUCTOR                     */
/* ************************************************************************** */

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {

	if (SHOWMSG)
		std::cout << COLOR("HumanB", GREENULINE) << COLOR(" Parametric constructor called", GREEN) << std::endl;
}

HumanB::~HumanB(void) {

	if (SHOWMSG)
		std::cout << COLOR("HumanB", REDULINE) << COLOR(" Default destructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                               MEMBER FUNCTION                              */
/* ************************************************************************** */

void	HumanB::attack(void) {

	if (this->_weapon != NULL && this->_weapon->getType() != "")
		std::cout << COLOR(this->_name, MAGENTAULINE) << COLOR(" attacks with their ", MAGENTA) << COLOR(this->_weapon->getType(), CYAN) << std::endl;
	else
		std::cout << COLOR(this->_name, REDULINE) << COLOR(" does not have a weapon to use", RED) << std::endl;
}

/* ************************************************************************** */
/*                                   SETTER                                   */
/* ************************************************************************** */

void	HumanB::setWeapon(Weapon& weapon) {

	this->_weapon = &weapon;
}
