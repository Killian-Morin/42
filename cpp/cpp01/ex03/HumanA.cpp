/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:38:14 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 10:36:09 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/* ************************************************************************** */
/*                      PARAMETRIC CONSTRUCTOR/DESTRUCTOR                     */
/* ************************************************************************** */

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {

	if (SHOWMSG)
		std::cout << COLOR("HumanA", GREENULINE) << COLOR(" Parametric constructor called", GREEN) << std::endl;
}

HumanA::~HumanA(void) {

	if (SHOWMSG)
		std::cout << COLOR("HumanA", REDULINE) << COLOR(" Default destructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                               MEMBER FUNCTION                              */
/* ************************************************************************** */

void	HumanA::attack(void) {

	std::cout << COLOR(this->_name, YELLOWULINE) << COLOR(" attacks with their ", YELLOW) << COLOR(this->_weapon.getType(), CYAN) << std::endl;
}
