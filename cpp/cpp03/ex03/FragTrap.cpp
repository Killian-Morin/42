/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:40:47 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/30 14:15:02 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_name = "default-name";
	std::cout << CYANULINE << "FragTrap " << this->_name << RESET;
	std::cout << COLOR(" Default constructor", BLUE) << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << CYANULINE << "FragTrap " << this->_name << RESET;
	std::cout << COLOR(" Default destructor", RED) << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	this->_name = other._name;
	std::cout << CYANULINE << "FragTrap " << this->_name << RESET;
	std::cout << COLOR(" Copy constructor", BLUE) << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& rhs)
{
	if (this != &rhs)
	{
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
		this->_name = rhs._name;
	}
	std::cout << CYANULINE << "FragTrap " << this->_name << RESET;
	std::cout << COLOR(" assignement operator called", BLUE) << std::endl;
	return (*this);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << CYANULINE << "FragTrap " << this->_name << RESET;
	std::cout << COLOR(" name initializer constructor", BLUE) << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << CYANULINE << "FragTrap " << this->_name << RESET;
		std::cout << COLOR(" is destroyed (no more hit points). He can't do any action.", YELLOW) << std::endl;
		this->printStatus();
		return ;
	}
	if (this->_energyPoints > 0)
	{
		this->_energyPoints -= 1;
		std::cout << CYANULINE << "FragTrap " << this->_name << RESET;
		std::cout << COLOR(" attacks ", YELLOW) << COLOR(target, YELLOWBACK);
		std::cout << YELLOW << ", causing " << this->_attackDamage << " points of damage!" << WHITE << std::endl;
	}
	else
	{
		std::cout << CYANULINE << "FragTrap " << this->_name << RESET;
		std::cout << COLOR(" has no more energy points left. He can't do any action.", YELLOW) << std::endl;
	}
	this->printStatus();
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_hitPoints == 0)
	{
		std::cout << CYANULINE << "FragTrap " << this->_name << RESET;
		std::cout << COLOR(" is destroyed (no more hit points). He can't do any action.", WHITEBACK) << std::endl;
		this->printStatus();
		return ;
	}
	if (this->_energyPoints > 0)
	{
		this->_energyPoints -= 1;
		std::cout << CYANULINE << "FragTrap " << this->_name << RESET << " " << COLOR("High fives ? 🙏", WHITEBACK) << std::endl;
		this->printStatus();
		return ;
	}
	else
	{
		std::cout << CYANULINE << "FragTrap " << this->_name << RESET;
		std::cout << COLOR(" has no more energy points left. He can't do any action.", WHITEBACK) << std::endl;
		this->printStatus();
	}
}

void	FragTrap::printStatus(void)
{
	std::cout << CYANULINE << "FragTrap " << this->_name << RESET;
	std::cout << WHITE << " now has " << this->_hitPoints << " hit points and ";
	std::cout << this->_energyPoints << " energy points." << std::endl << std::endl;
}
