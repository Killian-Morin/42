/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:58:24 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:31:36 by kmorin           ###   ########.fr       */
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

	this->_brain = new Brain();
}

Dog::Dog(const Dog& src) {

	this->_type = src._type;

	if (SHOWMSG)
		std::cout << COLOR("Dog 🐶", YELLOW) << COLOR(" Copy constructor called", GREEN) << std::endl;

	this->_brain = new Brain(*src._brain);
}

Dog&	Dog::operator=(const Dog& rhs) {

	if (this != &rhs) {
		this->_type = rhs._type;
		this->_brain = new Brain(*rhs._brain);
	}

	if (SHOWMSG)
		std::cout << COLOR("Dog 🐶", YELLOW) << COLOR(" Assignement operator called", GREEN) << std::endl;

	return (*this);
}

Dog::~Dog(void) {

	delete this->_brain;

	if (SHOWMSG)
		std::cout << COLOR("Dog 🐶", YELLOW) << COLOR(" Default destructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                        OVERLOADED HERITED FUNCTIONS                        */
/* ************************************************************************** */

void	Dog::makeSound(void) const {

	std::cout << COLOR("Dog 🐶", YELLOW) << COLOR(" makes a sound: Woof!", MAGENTA) << std::endl;
}

/* ************************************************************************** */
/*                                GETTER/SETTER                               */
/* ************************************************************************** */

std::string	Dog::getIdea(int index) const {

	return (this->_brain->getIdea(index));
}

void	Dog::setIdea(std::string idea, int index) {

	this->_brain->setIdea(idea, index);
}
