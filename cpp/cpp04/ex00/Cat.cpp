/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:58:18 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:31:16 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

Cat::Cat(void) : Animal() {

	this->_type = "Cat";

	if (SHOWMSG)
		std::cout << COLOR("Cat 🐈", CYAN) << COLOR(" Default constructor called", GREEN) << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src) {

	if (SHOWMSG)
		std::cout << COLOR("Cat 🐈", CYAN) << COLOR(" Copy constructor called", GREEN) << std::endl;
}

Cat&	Cat::operator=(const Cat& rhs) {

	if (this != &rhs)
		this->_type = rhs._type;

	if (SHOWMSG)
		std::cout << COLOR("Cat 🐈", CYAN) << COLOR(" Assignement operator called", GREEN) << std::endl;

	return (*this);
}

Cat::~Cat(void) {

	if (SHOWMSG)
		std::cout << COLOR("Cat 🐈", CYAN) << COLOR(" Default destructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                        OVERLOADED HERITED FUNCTIONS                        */
/* ************************************************************************** */

void	Cat::makeSound(void) const {

	std::cout << COLOR("Cat 🐈", CYAN) << COLOR(" makes a sound: Meow!", MAGENTA) << std::endl;
}

/* ************************************************************************** */
/*                                  WRONG CAT                                 */
/* ************************************************************************** */

WrongCat::WrongCat(void) : WrongAnimal() {

	this->_type = "WrongCat";

	if (SHOWMSG)
		std::cout << COLOR("WrongCat 🐈", CYAN) << COLOR(" Default constructor called", GREEN) << std::endl;
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src) {

	if (SHOWMSG)
		std::cout << COLOR("WrongCat 🐈", CYAN) << COLOR(" Copy constructor called", GREEN) << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& rhs) {

	if (this != &rhs)
		this->_type = rhs._type;

	if (SHOWMSG)
		std::cout << COLOR("WrongCat 🐈", CYAN) << COLOR(" Assignement operator called", GREEN) << std::endl;

	return (*this);
}

WrongCat::~WrongCat(void) {

	if (SHOWMSG)
		std::cout << COLOR("WrongCat 🐈", CYAN) << COLOR(" Default destructor called", RED) << std::endl;
}

void	WrongCat::makeSound(void) const {

	std::cout << COLOR("WrongCat 🐈", CYAN) << COLOR(" makes a sound: Meow!", MAGENTA) << std::endl;
}
