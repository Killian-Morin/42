/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:58:24 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/07 13:17:30 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ************************************************************************** */
/*                  CANONIC METHODS and SPECIAL CONSTRUCTORS                  */
/* ************************************************************************** */

Dog::Dog(void) : Animal()
{
	this->_type = "Dog";
	std::cout << COLOR("Dog 🐶", YELLOW);
	std::cout << COLOR(" Default constructor", BLUE) << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(const Dog& src)
{
	this->_type = src._type;
	std::cout << COLOR("Dog 🐶", YELLOW);
	std::cout << COLOR(" Copy constructor", BLUE) << std::endl;
	this->_brain = new Brain(*src._brain);
}

Dog&	Dog::operator=(const Dog& rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
		this->_brain = new Brain(*rhs._brain);
	}
	std::cout << COLOR("Dog 🐶", YELLOW);
	std::cout << COLOR(" assignement operator called", BLUE) << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << COLOR("Dog 🐶", YELLOW);
	std::cout << COLOR(" Default destructor", RED) << std::endl;
}

/* ************************************************************************** */
/*                              MEMBERS FUNCTIONS                             */
/* ************************************************************************** */

void	Dog::makeSound(void) const
{
	std::cout << COLOR("Dog 🐶", YELLOW);
	std::cout << COLOR(" makes a sound: Woof!", MAGENTA) << std::endl;
}

std::string	Dog::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}

void	Dog::setIdea(std::string idea, int index)
{
	this->_brain->setIdea(idea, index);
}
