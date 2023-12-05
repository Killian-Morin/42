/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:52:55 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/05 11:23:05 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("AAnimal_default")
{
	std::cout << COLOR("AAnimal", CYAN);
	std::cout << COLOR(" Default constructor ", BLUE) << std::endl;
}

AAnimal::AAnimal(const AAnimal& src)
{
	this->_type = src._type;
	std::cout << COLOR("AAnimal", CYAN);
	std::cout << COLOR(" Copy constructor", BLUE) << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal& rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	std::cout << COLOR("AAnimal", CYAN);
	std::cout << COLOR(" assignement operator called", BLUE) << std::endl;
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << COLOR("AAnimal", CYAN);
	std::cout << COLOR(" Default destructor", RED) << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return (this->_type);
}

void	AAnimal::makeSound(void) const
{
	std::cout << COLOR("Default AAnimal sound: ...", MAGENTA) << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */

WrongAAnimal::WrongAAnimal(void) : _type("WrongAAnimal_default")
{
	std::cout << COLOR("WrongAAnimal", CYAN);
	std::cout << COLOR(" Default constructor ", BLUE) << std::endl;
}

WrongAAnimal::WrongAAnimal(const WrongAAnimal& src)
{
	this->_type = src._type;
	std::cout << COLOR("WrongAAnimal", CYAN);
	std::cout << COLOR(" Copy constructor", BLUE) << std::endl;
}

WrongAAnimal&	WrongAAnimal::operator=(const WrongAAnimal& rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	std::cout << COLOR("WrongAAnimal", CYAN);
	std::cout << COLOR(" assignement operator called", BLUE) << std::endl;
	return (*this);
}

WrongAAnimal::~WrongAAnimal(void)
{
	std::cout << COLOR("WrongAAnimal", CYAN);
	std::cout << COLOR(" Default destructor", RED) << std::endl;
}

std::string	WrongAAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAAnimal::makeSound(void) const
{
	std::cout << COLOR("Default WrongAAnimal sound: ...", MAGENTA) << std::endl;
}
