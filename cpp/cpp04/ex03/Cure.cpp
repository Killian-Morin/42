/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:28:45 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:36:24 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

Cure::Cure(void) : AMateria("cure") {

	if (SHOWMSG)
		std::cout << COLOR("* ", GREEN) << COLOR("Cure", BLUE) << COLOR(": default constructor called *", GREEN) << std::endl;
}

Cure::Cure(Cure const& src) : AMateria(src) {

	*this = src;

	if (SHOWMSG)
		std::cout << COLOR("* ", GREEN) << COLOR("Cure", BLUE) << COLOR(": copy constructor called *", GREEN) << std::endl;
}

Cure& Cure::operator=(Cure const& rhs) {

	if (this != &rhs)
		this->_type = rhs._type;

	if (SHOWMSG)
		std::cout << COLOR("* ", GREEN) << COLOR("Cure", BLUE) << COLOR(": assignation operator called *", GREEN) << std::endl;

	return *this;
}

Cure::~Cure(void) {

	if (SHOWMSG)
		std::cout << COLOR("* ", GREEN) << COLOR("Cure", BLUE) << COLOR(": destructor called *", RED) << std::endl;
}

/* ************************************************************************** */
/*                        OVERLOADED HERITED FUNCTIONS                        */
/* ************************************************************************** */

AMateria* Cure::clone(void) const {

	return (new Cure(*this));
}

void Cure::use(ICharacter& target) {

	std::string	curType = this->_type;
	curType[0] = toupper(curType[0]);

	std::cout << COLOR(curType, MAGENTA) << COLOR(": * heals ", BLUE) << COLOR(target.getName(), MAGENTA) \
		<< COLOR("'s wounds *", BLUE) << std::endl;
}
