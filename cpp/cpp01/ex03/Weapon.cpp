/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:38:37 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/20 16:54:32 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weapon) : type(weapon)
{
}

Weapon::~Weapon()
{
	std::cout << "Weapon destructor is called" << std::endl;
}

const std::string Weapon::getType()
{
	return this->type;
}

void	Weapon::setType(std::string newType)
{
	this->type = newType;
}

// default constructor
Weapon::Weapon()
{
}
