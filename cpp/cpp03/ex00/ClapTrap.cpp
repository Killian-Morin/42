/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:55:46 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/29 17:32:24 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << BLUE << "ClapTrap Default constructor" << WHITE << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << RED << "ClapTrap Default destructor" << WHITE << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage), _name(other._name)
{
	std::cout << CYAN << "ClapTrap Copy constructor" << WHITE << std::endl;
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
	std::cout << CYAN << "ClapTrap assignement operator called" << WHITE << std::endl;
	return (*this);
}

ClapTrap::ClapTrap(std::string name) : _hitPoints(10), _energyPoints(10), _attackDamage(0), _name(name)
{
	std::cout << CYAN << "ClapTrap name initializer constructor" << WHITE << std::endl;
}

/*
ClapTrap <name> attacks <target>, causing <damage> points of damage!
*/
void	ClapTrap::attack(const std::string& target)
{
	this->_energyPoints -= 1;
	std::cout << std::endl << YELLOW << "ClapTrap " << this->_name << " attacks " << target;
	std::cout << ", causing " << this->_attackDamage << " points of damage!" << WHITE << std::endl << std::endl;
	// target.takedamage(this->_attackDamage);
}

/*
ClapTrap <name> takes <damage> points of damage!
*/
void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	std::cout << std::endl << MAGENTA << "ClapTrap " << this->_name << " takes " << amount;
	std::cout << " points of damage!" << WHITE << std::endl << std::endl;
}

/*
ClapTrap <name> repair itself to <amount> hit points back!
*/
void	ClapTrap::beRepaired(unsigned int amount)
{
	this->_energyPoints -= 1;
	this->_hitPoints += amount;
	std::cout << std::endl << GREEN << "ClapTrap " << this->_name << " repair itself to " << amount;
	std::cout << " hit points back!" << WHITE << std::endl << std::endl;
}
