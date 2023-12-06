/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:28:45 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/06 17:18:41 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/* ************************************************************************** */
/*                  CANONIC METHODS and SPECIAL CONSTRUCTORS                  */
/* ************************************************************************** */

Cure::Cure(void) : AMateria("cure")
{
	std::cout << COLOR("Cure default constructor called.", BLUE) << std::endl;
}

Cure::Cure(const Cure &src)
{
	(void)src;
	std::cout << COLOR("Cure copy constructor called.", BLUE) << std::endl;
}

Cure& Cure::operator=(const Cure &rhs)
{
	if (this != &rhs)
	{
	}
	std::cout << COLOR("Cure assignation operator called.", BLUE) << std::endl;
	return *this;
}

Cure::~Cure(void)
{
	std::cout << COLOR("Cure destructor called.", RED) << std::endl;
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
	std::cout << COLOR(_type, MAGENTA) << COLOR(" * heals ", GREEN) << COLOR(target.getName(), MAGENTA) \
		<< COLOR("'s wounds *", GREEN) << std::endl;
}
