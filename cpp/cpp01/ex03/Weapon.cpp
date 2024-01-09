/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:38:37 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 10:36:17 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/* ************************************************************************** */
/*                      PARAMETRIC CONSTRUCTOR/DESTRUCTOR                     */
/* ************************************************************************** */

Weapon::Weapon(std::string type) : _type(type) {

	if (SHOWMSG)
		std::cout << COLOR("Weapon", GREENULINE) << COLOR(" Parametric constructor called", GREEN) << std::endl;
}

Weapon::~Weapon(void) {

	if (SHOWMSG)
		std::cout << COLOR("Weapon", REDULINE) << COLOR(" Default destructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                                GETTER/SETTER                               */
/* ************************************************************************** */

const std::string& Weapon::getType(void) {

	return (this->_type);
}

void	Weapon::setType(std::string newType) {

	this->_type = newType;
	// std::cout << this->_type << std::endl;
}
