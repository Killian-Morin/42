/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:52:55 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/07 13:02:37 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* ************************************************************************** */
/*                  CANONIC METHODS and SPECIAL CONSTRUCTORS                  */
/* ************************************************************************** */

Animal::Animal(void) : _type("Animal_default")
{
	std::cout << COLOR("Animal", CYAN);
	std::cout << COLOR(" Default constructor ", BLUE) << std::endl;
}

Animal::Animal(const Animal& src) : _type(src._type)
{
	std::cout << COLOR("Animal", CYAN);
	std::cout << COLOR(" Copy constructor", BLUE) << std::endl;
}

Animal&	Animal::operator=(const Animal& rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	std::cout << COLOR("Animal", CYAN);
	std::cout << COLOR(" assignement operator called", BLUE) << std::endl;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << COLOR("Animal", CYAN);
	std::cout << COLOR(" Default destructor", RED) << std::endl;
}

/* ************************************************************************** */
/*                              MEMBERS FUNCTIONS                             */
/* ************************************************************************** */

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << COLOR("Default Animal sound: ...", MAGENTA) << std::endl;
}

/* ************************************************************************** */
/*                                WRONG ANIMAL                                */
/* ************************************************************************** */

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal_default")
{
	std::cout << COLOR("WrongAnimal", CYAN);
	std::cout << COLOR(" Default constructor ", BLUE) << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) : _type(src._type)
{
	std::cout << COLOR("WrongAnimal", CYAN);
	std::cout << COLOR(" Copy constructor", BLUE) << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	std::cout << COLOR("WrongAnimal", CYAN);
	std::cout << COLOR(" assignement operator called", BLUE) << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << COLOR("WrongAnimal", CYAN);
	std::cout << COLOR(" Default destructor", RED) << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << COLOR("Default WrongAnimal sound: ...", MAGENTA) << std::endl;
}
