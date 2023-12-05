/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:38:37 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/05 15:34:49 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
}

Weapon::~Weapon(void)
{
	// std::cout << COLOR("Weapon Default destructor called", RED) << WHITE << std::endl;
}

const std::string& Weapon::getType(void)
{
	return this->_type;
}

void	Weapon::setType(std::string newType)
{
	this->_type = newType;
	// std::cout << this->_type << std::endl;
}
