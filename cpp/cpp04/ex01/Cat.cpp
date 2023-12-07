/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:58:18 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/07 13:16:14 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ************************************************************************** */
/*                  CANONIC METHODS and SPECIAL CONSTRUCTORS                  */
/* ************************************************************************** */

Cat::Cat(void) : Animal()
{
	this->_type = "Cat";
	std::cout << COLOR("Cat 🐈", GREEN);
	std::cout << COLOR(" Default constructor", BLUE) << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(const Cat& src)
{
	this->_type = src._type;
	std::cout << COLOR("Cat 🐈", GREEN);
	std::cout << COLOR(" Copy constructor", BLUE) << std::endl;
	this->_brain = new Brain(*src._brain);
}

Cat&	Cat::operator=(const Cat& rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
		this->_brain = new Brain(*rhs._brain);
	}
	std::cout << COLOR("Cat 🐈", GREEN);
	std::cout << COLOR(" assignement operator called", BLUE) << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << COLOR("Cat 🐈", GREEN);
	std::cout << COLOR(" Default destructor", RED) << std::endl;
}

/* ************************************************************************** */
/*                              MEMBERS FUNCTIONS                             */
/* ************************************************************************** */

void	Cat::makeSound(void) const
{
	std::cout << COLOR("Cat 🐈", GREEN);
	std::cout << COLOR(" makes a sound: Meow!", MAGENTA) << std::endl;
}

std::string	Cat::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}

void	Cat::setIdea(std::string idea, int index)
{
	this->_brain->setIdea(idea, index);
}

/* ************************************************************************** */
/*                                 WRONG CAT                                  */
/* ************************************************************************** */

WrongCat::WrongCat(void) : WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << COLOR("WrongCat 🐈", GREEN);
	std::cout << COLOR(" Default constructor", BLUE) << std::endl;
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src)
{
	std::cout << COLOR("WrongCat 🐈", GREEN);
	std::cout << COLOR(" Copy constructor", BLUE) << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	std::cout << COLOR("WrongCat 🐈", GREEN);
	std::cout << COLOR(" assignement operator called", BLUE) << std::endl;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << COLOR("WrongCat 🐈", GREEN);
	std::cout << COLOR(" Default destructor", RED) << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << COLOR("WrongCat 🐈", GREEN);
	std::cout << COLOR(" makes a sound: Meow!", MAGENTA) << std::endl;
}
