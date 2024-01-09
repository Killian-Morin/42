/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:21:56 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 12:45:31 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap() {

	this->_name = ClapTrap::_name;
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;

	if (SHOWMSG)
		std::cout << YELLOW << "DiamondTrap " << this->_name << \
			COLOR(" Default constructor called", GREEN) << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) : ClapTrap(src), ScavTrap(src), FragTrap(src) {

	this->_name = src._name;
	this->ClapTrap::_name = src.ClapTrap::_name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;

	if (SHOWMSG)
		std::cout << YELLOW << "DiamondTrap " << this->_name << \
			COLOR(" Copy constructor called", GREEN) << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& rhs) {

	if (this != &rhs) {
		this->_name = rhs._name;
		this->ClapTrap::_name = rhs.ClapTrap::_name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}

	if (SHOWMSG)
		std::cout << YELLOW << "DiamondTrap " << this->_name << \
			COLOR(" Assignement operator called", GREEN) << std::endl;

	return (*this);
}

DiamondTrap::~DiamondTrap(void) {

	if (SHOWMSG)
		std::cout << YELLOW << "DiamondTrap " << this->_name << \
			COLOR(" Default destructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                           PARAMETRIC CONSTRUCTOR                           */
/* ************************************************************************** */

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name) {

	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;

	if (SHOWMSG)
		std::cout << YELLOW << "DiamondTrap " << this->_name << \
			COLOR(" Parametric constructor called", BLUE) << std::endl;
}

/* ************************************************************************** */
/*                               MEMBER FUNCTIONS                             */
/* ************************************************************************** */

void	DiamondTrap::attack(const std::string& target) {

	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) {

	std::cout << YELLOW << "DiamondTrap " << this->_name << std::endl << \
		COLOR("\t_name : ", WHITE) << COLOR(this->_name, YELLOWBACK) << std::endl << \
		COLOR("\tClapTrap _name : ", WHITE) << COLOR(this->ClapTrap::_name, YELLOWBACK) << std::endl << std::endl;
}
