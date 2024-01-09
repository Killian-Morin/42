/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:58:24 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:31:24 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

Dog::Dog(void) : Animal() {

	this->_type = "Dog";
	if (SHOWMSG)
		std::cout << COLOR("Dog 🐶", YELLOW) << COLOR(" Default constructor called", GREEN) << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src) {

	if (SHOWMSG)
		std::cout << COLOR("Dog 🐶", YELLOW) << COLOR(" Copy constructor called", GREEN) << std::endl;
}

Dog&	Dog::operator=(const Dog& rhs) {

	if (this != &rhs)
		this->_type = rhs._type;

	if (SHOWMSG)
		std::cout << COLOR("Dog 🐶", YELLOW) << COLOR(" Assignement operator called", GREEN) << std::endl;

	return (*this);
}

Dog::~Dog(void) {

	if (SHOWMSG)
		std::cout << COLOR("Dog 🐶", YELLOW) << COLOR(" Default destructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                        OVERLOADED HERITED FUNCTIONS                        */
/* ************************************************************************** */

void	Dog::makeSound(void) const {

	std::cout << COLOR("Dog 🐶", YELLOW) << COLOR(" makes a sound: Woof!", MAGENTA) << std::endl;
}
