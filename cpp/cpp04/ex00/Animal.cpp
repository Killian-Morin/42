/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:52:55 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 14:28:50 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

Animal::Animal(void) : _type("Animal_default") {

	if (SHOWMSG)
		std::cout << COLOR("Animal", BLUE) << COLOR(" Default constructor called", GREEN) << std::endl;
}

Animal::Animal(const Animal& src) : _type(src._type) {

	if (SHOWMSG)
		std::cout << COLOR("Animal", BLUE) << COLOR(" Copy constructor called", GREEN) << std::endl;
}

Animal&	Animal::operator=(const Animal& rhs) {

	if (this != &rhs)
		this->_type = rhs._type;

	if (SHOWMSG)
		std::cout << COLOR("Animal", BLUE) << COLOR(" Assignement operator called", GREEN) << std::endl;

	return (*this);
}

Animal::~Animal(void) {

	if (SHOWMSG)
		std::cout << COLOR("Animal", BLUE) << COLOR(" Default destructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                              MEMBER FUNCTION                              */
/* ************************************************************************** */

void	Animal::makeSound(void) const {

	std::cout << COLOR("Default Animal sound: ...", MAGENTA) << std::endl;
}

/* ************************************************************************** */
/*                                   GETTER                                   */
/* ************************************************************************** */

std::string	Animal::getType(void) const {

	return (this->_type);
}

/* ************************************************************************** */
/*                                WRONG ANIMAL                                */
/* ************************************************************************** */

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal_default") {

	if (SHOWMSG)
		std::cout << COLOR("WrongAnimal", BLUE) << COLOR(" Default constructor called", BLUE) << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) : _type(src._type) {

	if (SHOWMSG)
		std::cout << COLOR("WrongAnimal", BLUE) << COLOR(" Copy constructor called", BLUE) << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& rhs) {

	if (this != &rhs)
		this->_type = rhs._type;

	if (SHOWMSG)
		std::cout << COLOR("WrongAnimal", BLUE) << COLOR(" Assignement operator called", BLUE) << std::endl;

	return (*this);
}

WrongAnimal::~WrongAnimal(void) {

	if (SHOWMSG)
		std::cout << COLOR("WrongAnimal", BLUE) << COLOR(" Default destructor called", RED) << std::endl;
}

void	WrongAnimal::makeSound(void) const {

	std::cout << COLOR("Default WrongAnimal sound: ...", MAGENTA) << std::endl;
}

std::string	WrongAnimal::getType(void) const {

	return (this->_type);
}
