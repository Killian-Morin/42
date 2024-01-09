/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:04:14 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 10:35:53 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* ************************************************************************** */
/*                           Constructor/Destructor                           */
/* ************************************************************************** */

//Default Constructor in private
Zombie::Zombie(void) {

	std::cout << COLOR("Default constructor called", GREEN) << std::endl;
}

Zombie::~Zombie(void) {

	std::cout << COLOR("Zombie ", RED) << COLOR(this->_name, REDULINE) << COLOR(" has been destroyed", RED) << std::endl;
}

/* ************************************************************************** */
/*                           PARAMETRIC CONSTRUCTOR                           */
/* ************************************************************************** */

Zombie::Zombie(std::string tmp) : _name(tmp) {

	std::cout << COLOR("Zombie ", GREEN) << COLOR(this->_name, GREENULINE) << COLOR(" has been created", GREEN) << std::endl;
}

/* ************************************************************************** */
/*                              MEMBER FUNCTION                              */
/* ************************************************************************** */

void	Zombie::announce(void) {

	std::cout << COLOR("Zombie ", YELLOW) << COLOR(this->_name, YELLOWULINE) << COLOR(": BraiiiiiiinnnzzzZ...", YELLOW) << std::endl;
}
