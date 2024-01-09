/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:34:03 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 12:35:01 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

ScavTrap::ScavTrap(void) : _guardStatus(false) {

	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_name = "default-name";

	if (SHOWMSG)
		std::cout << CYANBACK << "ScavTrap " << this->_name << \
			COLOR(" Default constructor called", GREEN) << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src), _guardStatus(src._guardStatus) {

	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	this->_name = src._name;
	this->_guardStatus = src._guardStatus;

	if (SHOWMSG)
		std::cout << CYANBACK << "ScavTrap " << this->_name << \
			COLOR(" Copy constructor called", GREEN) << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& rhs) {

	if (this != &rhs) {
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
		this->_name = rhs._name;
		this->_guardStatus = rhs._guardStatus;
	}

	if (SHOWMSG)
		std::cout << CYANBACK << "ScavTrap " << this->_name << \
			COLOR(" Assignement operator called", GREEN) << std::endl;

	return (*this);
}

ScavTrap::~ScavTrap(void) {

	if (SHOWMSG)
		std::cout << CYANBACK << "ScavTrap " << this->_name << \
			COLOR(" Default destructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                           PARAMETRIC CONSTRUCTOR                           */
/* ************************************************************************** */

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _guardStatus(false) {

	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	if (SHOWMSG)
		std::cout << CYANBACK << "ScavTrap " << this->_name << \
			COLOR(" Parametric constructor called", BLUE) << std::endl;
}

/* ************************************************************************** */
/*                               MEMBER FUNCTIONS                             */
/* ************************************************************************** */

void	ScavTrap::attack(const std::string& target) {

	if (this->_hitPoints == 0) {
		std::cout << CYANBACK << "ScavTrap " << this->_name << \
			COLOR(" is destroyed (no more hit points). He can't do any action.", YELLOW) << std::endl;

		this->printStatus();

		return ;
	}

	if (this->_energyPoints > 0) {
		this->_energyPoints -= 1;

		std::cout << CYANBACK << "ScavTrap " << this->_name << \
			COLOR(" attacks ", YELLOW) << COLOR(target, YELLOWBOLD) << COLOR(", causing ", YELLOW) << \
			COLOR(this->_attackDamage, YELLOWULINE) << COLOR(" points of damage!", YELLOW) << std::endl;
	}
	else {
		std::cout << CYANBACK << "ScavTrap " << this->_name << \
			COLOR(" has no more energy points left. He can't do any action.", YELLOW) << std::endl;
	}

	this->printStatus();
}

void	ScavTrap::guardGate(void) {

	if (this->_hitPoints == 0) {
		std::cout << CYANBACK << "ScavTrap " << this->_name << RESET << " " << \
			COLOR("is destroyed (no more hit points). He can't do any action.", WHITEULINE) << std::endl;

		this->printStatus();

		return ;
	}

	if (this->_energyPoints > 0) {
		if (this->_guardStatus == false) {
			this->_guardStatus = true;
			this->_energyPoints -= 1;

			std::cout << CYANBACK << "ScavTrap " << this->_name << RESET << " is now in " << \
				COLOR("Gate keeper mode.", WHITEULINE) << std::endl;

			this->printStatus();

			return ;
		}
		else {
			this->_guardStatus = false;
			this->_energyPoints -= 1;

			std::cout << CYANBACK << "ScavTrap " << this->_name << RESET << " is now in " << \
				COLOR("normal mode.", WHITEULINE) << std::endl;

			this->printStatus();

			return ;
		}
	}
	else {
		std::cout << CYANBACK << "ScavTrap " << this->_name << RESET << " " << \
			COLOR("has no more energy points left. He can't do any action.", WHITEULINE) << std::endl;

		this->printStatus();
	}
}

/* ************************************************************************** */
/*                               EXTRA FUNCTION                               */
/* ************************************************************************** */

void	ScavTrap::printStatus(void) {

	std::cout << CYANBACK << "ScavTrap " << this->_name << RESET << \
		" now has " << COLOR(this->_hitPoints, WHITEULINE) << " hit points, " << \
		COLOR(this->_energyPoints, WHITEULINE) << " energy points and is in ";

	if (this->_guardStatus == true)
		std::cout << COLOR("Gate keeper mode.", WHITEULINE);
	else
		std::cout << COLOR("normal mode.", WHITEULINE);

	std::cout << std::endl << std::endl;
}
