/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:28:44 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/06 17:19:20 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/* ************************************************************************** */
/*                  CANONIC METHODS and SPECIAL CONSTRUCTORS                  */
/* ************************************************************************** */

Ice::Ice(void) : AMateria("ice")
{
	std::cout << COLOR("Ice default constructor called.", BLUE) << std::endl;
}

Ice::Ice(const Ice &src)
{
	(void)src;
	std::cout << COLOR("Ice copy constructor called.", BLUE) << std::endl;
}

Ice& Ice::operator=(const Ice &rhs)
{
	if (this != &rhs)
	{
	}
	std::cout << COLOR("Ice assignation operator called.", BLUE) << std::endl;
	return *this;
}

Ice::~Ice(void)
{
	std::cout << COLOR("Ice destructor called.", RED) << std::endl;
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
	std::cout << COLOR(_type, MAGENTA) << COLOR(" * shoots an ice bolt at ", CYAN) << COLOR(target.getName(), MAGENTA) \
	<< COLOR(" *", CYAN) << std::endl;
}
