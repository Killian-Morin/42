/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:21:56 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/30 15:42:06 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
	this->_name = ClapTrap::_name;
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << YELLOW << "DiamondTrap " << this->_name;
	std::cout << COLOR(" Default constructor", BLUE) << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << YELLOW << "DiamondTrap " << this->_name;
	std::cout << COLOR(" Default destructor", RED) << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	this->_name = other._name;
	this->ClapTrap::_name = other.ClapTrap::_name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	std::cout << YELLOW << "DiamondTrap " << this->_name << RESET;
	std::cout << COLOR(" Copy constructor", BLUE) << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->ClapTrap::_name = rhs.ClapTrap::_name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	std::cout << YELLOW << "DiamondTrap " << this->_name << RESET;
	std::cout << COLOR(" assignement operator called", BLUE) << std::endl;
	return (*this);
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << YELLOW << "DiamondTrap " << this->_name;
	std::cout << COLOR(" name initializer constructor", BLUE) << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << YELLOW << "DiamondTrap " << this->_name << std::endl;
	std::cout << COLOR("\t_name : ", WHITE) << COLOR(this->_name, YELLOWBACK) << std::endl;
	std::cout << COLOR("\tClapTrap _name : ", WHITE) << COLOR(this->ClapTrap::_name, YELLOWBACK) << std::endl << std::endl;
}
