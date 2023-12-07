/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:28:45 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/07 09:55:48 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/* ************************************************************************** */
/*                  CANONIC METHODS and SPECIAL CONSTRUCTORS                  */
/* ************************************************************************** */

Cure::Cure(void) : AMateria("cure")
{
	std::cout << COLOR("* ", BLUE) << COLOR("Cure", GREEN) << \
		COLOR(": default constructor called *", BLUE) << std::endl;
}

Cure::Cure(Cure const& src) : AMateria(src)
{
	*this = src;
	std::cout << COLOR("* ", BLUE) << COLOR("Cure", GREEN) << \
		COLOR(": copy constructor called *", BLUE) << std::endl;
}

Cure& Cure::operator=(Cure const& rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	std::cout << COLOR("* ", BLUE) << COLOR("Cure", GREEN) << \
		COLOR(": assignation operator called *", BLUE) << std::endl;
	return *this;
}

Cure::~Cure(void)
{
	std::cout << COLOR("* ", BLUE) << COLOR("Cure", GREEN) << \
		COLOR(": destructor called *", RED) << std::endl;
}

/* ************************************************************************** */
/*                              MEMBERS FUNCTIONS                             */
/* ************************************************************************** */

AMateria* Cure::clone(void) const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::string	curType = this->_type;
	curType[0] = toupper(curType[0]);
	std::cout << COLOR(curType, MAGENTA) << COLOR(": * heals ", GREEN) << COLOR(target.getName(), MAGENTA) \
		<< COLOR("'s wounds *", GREEN) << std::endl;
}
