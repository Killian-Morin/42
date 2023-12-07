/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:28:44 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/07 09:56:58 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/* ************************************************************************** */
/*                  CANONIC METHODS and SPECIAL CONSTRUCTORS                  */
/* ************************************************************************** */

Ice::Ice(void) : AMateria("ice")
{
	std::cout << COLOR("* ", BLUE) << COLOR("Ice", CYAN) << \
		COLOR(": default constructor called *", BLUE) << std::endl;
}

Ice::Ice(Ice const& src) : AMateria(src)
{
	*this = src;
	std::cout << COLOR("* ", BLUE) << COLOR("Ice", CYAN) << \
		COLOR(": copy constructor called *", BLUE) << std::endl;
}

Ice& Ice::operator=(Ice const& rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	std::cout << COLOR("* ", BLUE) << COLOR("Ice", CYAN) << \
		COLOR(": assignation operator called *", BLUE) << std::endl;
	return *this;
}

Ice::~Ice(void)
{
	std::cout << COLOR("* ", BLUE) << COLOR("Ice", CYAN) << \
		COLOR(": destructor called *", RED) << std::endl;
}

/* ************************************************************************** */
/*                              MEMBERS FUNCTIONS                             */
/* ************************************************************************** */

AMateria* Ice::clone(void) const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::string	curType = this->_type;
	curType[0] = toupper(curType[0]);
	std::cout << COLOR(curType, MAGENTA) << COLOR(": * shoots an ice bolt at ", CYAN) << COLOR(target.getName(), MAGENTA) \
		<< COLOR(" *", CYAN) << std::endl;
}
