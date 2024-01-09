/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:55:46 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 12:13:12 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

ClapTrap::ClapTrap(void) : _hitPoints(10), _energyPoints(10), _attackDamage(0), _name("default-name") {

	if (SHOWMSG)
		std::cout << CYAN << "ClapTrap " << this->_name << \
			COLOR(" Default constructor called", GREEN) << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src) : _hitPoints(src._hitPoints), _energyPoints(src._energyPoints), _attackDamage(src._attackDamage), _name(src._name){

	if (SHOWMSG)
		std::cout << CYAN << "ClapTrap " << this->_name << \
			COLOR(" Copy constructor called", GREEN) << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& rhs) {

	if (this != &rhs) {
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
		this->_name = rhs._name;
	}

	if (SHOWMSG)
		std::cout << CYAN << "ClapTrap " << this->_name << \
			COLOR(" Assignement operator called", GREEN) << std::endl;

	return (*this);
}

ClapTrap::~ClapTrap(void) {

	if (SHOWMSG)
		std::cout << CYAN << "ClapTrap " << this->_name << \
			COLOR(" Default destructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                           PARAMETRIC CONSTRUCTOR                           */
/* ************************************************************************** */

ClapTrap::ClapTrap(std::string name) : _hitPoints(10), _energyPoints(10), _attackDamage(0), _name(name) {

	if (SHOWMSG)
		std::cout << CYAN << "ClapTrap " << this->_name << \
			COLOR(" Parametric constructor called", GREEN) << std::endl;
}

/* ************************************************************************** */
/*                               MEMBER FUNCTIONS                             */
/* ************************************************************************** */

void	ClapTrap::attack(const std::string& target) {

	if (this->_hitPoints == 0) {
		std::cout << CYAN << "ClapTrap " << this->_name << \
			COLOR(" is destroyed (no more hit points). He can't do any action.", YELLOW) << std::endl;

		this->printStatus();

		return ;
	}

	if (this->_energyPoints > 0) {
		this->_energyPoints -= 1;

		std::cout << CYAN << "ClapTrap " << this->_name << \
			COLOR(" attacks ", YELLOW) << COLOR(target, CYAN) << COLOR(", causing ", YELLOW) << \
			COLOR(this->_attackDamage, YELLOWULINE) << COLOR(" points of damage!", YELLOW) << std::endl;
	}
	else {
		std::cout << CYAN << "ClapTrap " << this->_name << \
			COLOR(" has no more energy points left. He can't do any action.", YELLOW) << std::endl;
	}

	this->printStatus();
}

void	ClapTrap::takeDamage(unsigned int amount) {

	if (this->_hitPoints == 0) {

		std::cout << CYAN << "ClapTrap " << this->_name << \
			COLOR(" is already destroyed (no more hit points). He can't do any action.", MAGENTA) << std::endl;

		this->printStatus();

		return ;
	}

	if ((long) this->_hitPoints - (long) amount < 0)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;

	if (this->_hitPoints <= 0) {
		std::cout << CYAN << "ClapTrap " << this->_name << \
			COLOR(" has been destroyed.", MAGENTA) << std::endl;
	}
	else {
		std::cout << CYAN << "ClapTrap " << this->_name << \
			COLOR(" takes ", MAGENTA) << COLOR(amount, MAGENTAULINE) << COLOR(" points of damage!", MAGENTA) << std::endl;
	}

	this->printStatus();
}

void	ClapTrap::beRepaired(unsigned int amount) {

	if (this->_hitPoints == 0) {
		std::cout << CYAN << "ClapTrap " << this->_name << \
			COLOR(" is destroyed (no more hit points). He can't do any action.", BLUE) << std::endl;

		this->printStatus();

		return ;
	}

	if (this->_energyPoints > 0) {
		this->_energyPoints -= 1;
		this->_hitPoints += amount;

		std::cout << CYAN << "ClapTrap " << this->_name << \
			COLOR(" repairs itself and gains ", BLUE) << COLOR(amount, BLUEULINE) << COLOR(" hit points back!", BLUE) << std::endl;
	}
	else {
		std::cout << CYAN << "ClapTrap " << this->_name << \
			COLOR(" has no more energy points left. He can't do any action.", BLUE) << std::endl;
	}

	this->printStatus();
}

/* ************************************************************************** */
/*                               GETTERS/SETTER                               */
/* ************************************************************************** */

unsigned int	ClapTrap::getHitPoints(void) const {

	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const {

	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const {

	return (this->_attackDamage);
}

void	ClapTrap::setName(std::string name) {

	this->_name = name;
}

/* ************************************************************************** */
/*                               EXTRA FUNCTION                               */
/* ************************************************************************** */

void	ClapTrap::printStatus(void) {

	std::cout << CYAN << "ClapTrap " << this->_name << \
		WHITE << " now has " << COLOR(this->_hitPoints, CYANULINE) << " hit points and " << \
		COLOR(this->_energyPoints, CYANULINE) << " energy points." << std::endl << std::endl;
}
