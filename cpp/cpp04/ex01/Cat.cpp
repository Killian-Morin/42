/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:58:18 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:31:31 by kmorin           ###   ########.fr       */
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

	this->_brain = new Brain();
}

Cat::Cat(const Cat& src) {

	this->_type = src._type;

	if (SHOWMSG)
		std::cout << COLOR("Cat 🐈", CYAN) << COLOR(" Copy constructor called", GREEN) << std::endl;

	this->_brain = new Brain(*src._brain);
}

Cat&	Cat::operator=(const Cat& rhs) {

	if (this != &rhs) {
		this->_type = rhs._type;
		this->_brain = new Brain(*rhs._brain);
	}

	if (SHOWMSG)
		std::cout << COLOR("Cat 🐈", CYAN) << COLOR(" Assignement operator called", GREEN) << std::endl;

	return (*this);
}

Cat::~Cat(void) {

	delete this->_brain;

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
/*                                GETTER/SETTER                               */
/* ************************************************************************** */

std::string	Cat::getIdea(int index) const {

	return (this->_brain->getIdea(index));
}

void	Cat::setIdea(std::string idea, int index) {

	this->_brain->setIdea(idea, index);
}
