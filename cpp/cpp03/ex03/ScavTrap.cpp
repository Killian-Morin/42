/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:34:03 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/30 13:48:19 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : _guardStatus(false)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_name = "default-name";
	std::cout << CYANBACK << "ScavTrap " << this->_name << RESET;
	std::cout << COLOR(" Default constructor", BLUE) << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << CYANBACK << "ScavTrap " << this->_name << RESET;
	std::cout << COLOR(" Default destructor", RED) << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other), _guardStatus(other._guardStatus)
{
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	this->_name = other._name;
	this->_guardStatus = other._guardStatus;
	std::cout << CYANBACK << "ScavTrap " << this->_name << RESET;
	std::cout << COLOR(" Copy constructor", BLUE) << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& rhs)
{
	if (this != &rhs)
	{
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
		this->_name = rhs._name;
		this->_guardStatus = rhs._guardStatus;
	}
	std::cout << CYANBACK << "ScavTrap " << this->_name << RESET;
	std::cout << COLOR(" assignement operator called", BLUE) << std::endl;
	return (*this);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _guardStatus(false)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << CYANBACK << "ScavTrap " << this->_name << RESET;
	std::cout << COLOR(" name initializer constructor", BLUE) << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << CYANBACK << "ScavTrap " << this->_name << RESET;
		std::cout << COLOR(" is destroyed (no more hit points). He can't do any action.", YELLOW) << std::endl;
		this->printStatus();
		return ;
	}
	if (this->_energyPoints > 0)
	{
		this->_energyPoints -= 1;
		std::cout << CYANBACK << "ScavTrap " << this->_name << RESET;
		std::cout << COLOR(" attacks ", YELLOW) << COLOR(target, YELLOWBACK);
		std::cout << YELLOW << ", causing " << this->_attackDamage << " points of damage!" << WHITE << std::endl;
	}
	else
	{
		std::cout << CYANBACK << "ScavTrap " << this->_name << RESET;
		std::cout << COLOR(" has no more energy points left. He can't do any action.", YELLOW) << std::endl;
	}
	this->printStatus();
}

void	ScavTrap::guardGate(void)
{
	if (this->_hitPoints == 0)
	{
		std::cout << CYANBACK << "ScavTrap " << this->_name << RESET;
		std::cout << COLOR(" is destroyed (no more hit points). He can't do any action.", WHITEULINE) << std::endl;
		this->printStatus();
		return ;
	}
	if (this->_energyPoints > 0)
	{
		if (this->_guardStatus == false)
		{
			this->_guardStatus = true;
			this->_energyPoints -= 1;
			std::cout << CYANBACK << "ScavTrap " << this->_name << RESET << " is now in ";
			std::cout << COLOR("Gate keeper mode.", WHITEULINE) << std::endl;
			this->printStatus();
			return ;
		}
		else
		{
			this->_guardStatus = false;
			this->_energyPoints -= 1;
			std::cout << CYANBACK << "ScavTrap " << this->_name << RESET << " is now in ";
			std::cout << COLOR("normal mode.", WHITEULINE) << std::endl;
			this->printStatus();
			return ;
		}
	}
	else
	{
		std::cout << CYANBACK << "ScavTrap " << this->_name << RESET;
		std::cout << COLOR(" has no more energy points left. He can't do any action.", WHITEULINE) << std::endl;
		this->printStatus();
	}
}

void	ScavTrap::printStatus(void)
{
	std::cout << CYANBACK << "ScavTrap " << this->_name << RESET;
	std::cout << WHITE << " now has " << this->_hitPoints << " hit points, ";
	std::cout << this->_energyPoints << " energy points and is in ";
	if (this->_guardStatus == true)
	{
		std::cout << COLOR("Gate keeper mode.", WHITEULINE);
	}
	else
	{
		std::cout << COLOR("normal mode.", WHITEULINE);
	}
	std::cout << std::endl << std::endl;
}
