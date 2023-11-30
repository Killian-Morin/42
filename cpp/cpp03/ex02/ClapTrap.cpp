/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:55:46 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/30 12:59:08 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _hitPoints(10), _energyPoints(10), _attackDamage(0), _name("default-name")
{
	std::cout << CYAN << "ClapTrap " << this->_name;
	std::cout << COLOR(" Default constructor", BLUE) << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << CYAN << "ClapTrap " << this->_name;
	std::cout << COLOR(" Default destructor", RED) << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	this->_name = other._name;
	std::cout << CYAN << "ClapTrap " << this->_name;
	std::cout << COLOR(" Copy constructor", BLUE) << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& rhs)
{
	if (this != &rhs)
	{
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
		this->_name = rhs._name;
	}
	std::cout << CYAN << "ClapTrap " << this->_name;
	std::cout << COLOR(" assignement operator called", BLUE) << std::endl;
	return (*this);
}

ClapTrap::ClapTrap(std::string name) : _hitPoints(10), _energyPoints(10), _attackDamage(0), _name(name)
{
	std::cout << CYAN << "ClapTrap " << this->_name;
	std::cout << COLOR(" name initializer constructor", BLUE) << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << CYAN << "ClapTrap " << this->_name;
		std::cout << COLOR(" is destroyed (no more hit points). He can't do any action.", YELLOW) << std::endl;
		this->printStatus();
		return ;
	}
	if (this->_energyPoints > 0)
	{
		this->_energyPoints -= 1;
		std::cout << CYAN << "ClapTrap " << this->_name;
		std::cout << COLOR(" attacks ", YELLOW) << COLOR(target, CYAN);
		std::cout << YELLOW << ", causing " << this->_attackDamage << " points of damage!" << WHITE << std::endl;
	}
	else
	{
		std::cout << CYAN << "ClapTrap " << this->_name;
		std::cout << COLOR(" has no more energy points left. He can't do any action.", YELLOW) << std::endl;
	}
	this->printStatus();
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << CYAN << "ClapTrap " << this->_name;
		std::cout << COLOR(" is already destroyed (no more hit points). He can't do any action.", MAGENTA) << std::endl;
		this->printStatus();
		return ;
	}
	if ((long) this->_hitPoints - (long) amount < 0)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	if (this->_hitPoints <= 0)
	{
		std::cout << CYAN << "ClapTrap " << this->_name;
		std::cout << COLOR(" has been destroyed.", MAGENTA) << std::endl;
	}
	else
	{
		std::cout << CYAN << "ClapTrap " << this->_name;
		std::cout << MAGENTA << " takes " << amount << " points of damage!" << WHITE << std::endl;
	}
	this->printStatus();
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << CYAN << "ClapTrap " << this->_name;
		std::cout << COLOR(" is destroyed (no more hit points). He can't do any action.", GREEN) << std::endl;
		this->printStatus();
		return ;
	}
	if (this->_energyPoints > 0)
	{
		this->_energyPoints -= 1;
		this->_hitPoints += amount;
		std::cout << CYAN << "ClapTrap " << this->_name;
		std::cout << GREEN << " repairs itself and gains " << amount << " hit points back!" << std::endl;
	}
	else
	{
		std::cout << CYAN << "ClapTrap " << this->_name;
		std::cout << COLOR(" has no more energy points left. He can't do any action.", GREEN) << std::endl;
	}
	this->printStatus();
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

void	ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void	ClapTrap::printStatus(void)
{
	std::cout << CYAN << "ClapTrap " << this->_name;
	std::cout << WHITE << " now has " << this->_hitPoints << " hit points and ";
	std::cout << this->_energyPoints << " energy points." << std::endl << std::endl;
}
