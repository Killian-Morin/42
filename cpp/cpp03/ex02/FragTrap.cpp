/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:40:47 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 12:41:20 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

FragTrap::FragTrap(void) {

	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_name = "default-name";

	if (SHOWMSG)
		std::cout << CYANULINE << "FragTrap " << this->_name << \
			COLOR(" Default constructor called", GREEN) << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src) {

	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	this->_name = src._name;

	if (SHOWMSG)
		std::cout << CYANULINE << "FragTrap " << this->_name << \
			COLOR(" Copy constructor called", GREEN) << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& rhs) {

	if (this != &rhs)
	{
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
		this->_name = rhs._name;
	}

	if (SHOWMSG)
		std::cout << CYANULINE << "FragTrap " << this->_name << \
			COLOR(" Assignement operator called", GREEN) << std::endl;

	return (*this);
}

FragTrap::~FragTrap(void) {

	if (SHOWMSG)
		std::cout << CYANULINE << "FragTrap " << this->_name << \
			COLOR(" Default destructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                           PARAMETRIC CONSTRUCTOR                           */
/* ************************************************************************** */

FragTrap::FragTrap(std::string name) : ClapTrap(name) {

	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	if (SHOWMSG)
		std::cout << CYANULINE << "FragTrap " << this->_name << \
			COLOR(" Parametric constructor called", GREEN) << std::endl;
}

/* ************************************************************************** */
/*                               MEMBER FUNCTIONS                             */
/* ************************************************************************** */

void	FragTrap::highFivesGuys(void) {

	if (this->_hitPoints == 0) {
		std::cout << CYANULINE << "FragTrap " << this->_name << RESET << " " << \
			COLOR("is destroyed (no more hit points). He can't do any action.", WHITEBACK) << std::endl;

		this->printStatus();

		return ;
	}

	if (this->_energyPoints > 0) {
		this->_energyPoints -= 1;

		std::cout << CYANULINE << "FragTrap " << this->_name << RESET << " " << COLOR("High fives ? 🙏", WHITEBACK) << std::endl;

		this->printStatus();

		return ;
	}
	else {
		std::cout << CYANULINE << "FragTrap " << this->_name << RESET << " " << \
			COLOR("has no more energy points left. He can't do any action.", WHITEBACK) << std::endl;

		this->printStatus();
	}
}

/* ************************************************************************** */
/*                               EXTRA FUNCTION                               */
/* ************************************************************************** */

void	FragTrap::printStatus(void) {

	std::cout << CYANULINE << "FragTrap " << this->_name << \
		WHITE << " now has " << this->_hitPoints << " hit points and " << \
		this->_energyPoints << " energy points." << std::endl << std::endl;
}
