/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:28:44 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:36:16 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

Ice::Ice(void) : AMateria("ice") {

	if (SHOWMSG)
		std::cout << COLOR("* ", GREEN) << COLOR("Ice", CYAN) << COLOR(": default constructor called *", GREEN) << std::endl;
}

Ice::Ice(Ice const& src) : AMateria(src) {

	*this = src;

	if (SHOWMSG)
		std::cout << COLOR("* ", GREEN) << COLOR("Ice", CYAN) << COLOR(": copy constructor called *", GREEN) << std::endl;
}

Ice& Ice::operator=(Ice const& rhs) {

	if (this != &rhs)
		this->_type = rhs._type;

	if (SHOWMSG)
		std::cout << COLOR("* ", GREEN) << COLOR("Ice", CYAN) << COLOR(": assignation operator called *", GREEN) << std::endl;

	return *this;
}

Ice::~Ice(void) {

	if (SHOWMSG)
		std::cout << COLOR("* ", GREEN) << COLOR("Ice", CYAN) << COLOR(": destructor called *", RED) << std::endl;
}

/* ************************************************************************** */
/*                        OVERLOADED HERITED FUNCTIONS                        */
/* ************************************************************************** */

AMateria* Ice::clone(void) const {

	return (new Ice(*this));
}

void Ice::use(ICharacter& target) {

	std::string	curType = this->_type;
	curType[0] = toupper(curType[0]);

	std::cout << COLOR(curType, MAGENTA) << COLOR(": * shoots an ice bolt at ", CYAN) << COLOR(target.getName(), MAGENTA) \
		<< COLOR(" *", CYAN) << std::endl;
}
