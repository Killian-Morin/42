/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:01:34 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/07 13:58:24 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/* ************************************************************************** */
/*                  CANONIC METHODS and SPECIAL CONSTRUCTORS                  */
/* ************************************************************************** */

AMateria::AMateria(void)
{
	std::cout << COLOR("AMateria default constructor called.", BLUE) << std::endl;
}

AMateria::AMateria(AMateria const& src) : _type(src._type)
{
	std::cout << COLOR("AMateria copy constructor called.", BLUE) << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << COLOR("AMateria parametric constructor called.", BLUE) << std::endl;
}

AMateria& AMateria::operator=(AMateria const& rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	std::cout << COLOR("AMateria assignation operator called.", BLUE) << std::endl;
	return *this;
}

AMateria::~AMateria(void)
{
	std::cout << COLOR("AMateria destructor called.", RED) << std::endl;
}

/* ************************************************************************** */
/*                              MEMBERS FUNCTIONS                             */
/* ************************************************************************** */

std::string const & AMateria::getType(void) const
{
	return (this->_type);
}

/*
	No implementation of clone() since it's a virtual pure function
*/

void AMateria::use(ICharacter& target)
{
	std::cout << COLOR(_type, MAGENTA) << COLOR("* used ", RED) << COLOR("use(ICharacter& target) ", MAGENTAULINE) << \
		COLOR("from a non-existing AMateria at ", RED) << COLOR(target.getName(), MAGENTA) << COLOR("*", RED) << std::endl;
}
