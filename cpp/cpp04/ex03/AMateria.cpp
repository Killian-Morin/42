/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:01:34 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 14:44:35 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

AMateria::AMateria(void) {

	if (SHOWMSG)
		std::cout << COLOR("AMateria default constructor called.", GREEN) << std::endl;
}

AMateria::AMateria(AMateria const& src) : _type(src._type) {

	if (SHOWMSG)
		std::cout << COLOR("AMateria copy constructor called.", GREEN) << std::endl;
}

AMateria& AMateria::operator=(AMateria const& rhs) {

	if (this != &rhs)
		this->_type = rhs._type;

	if (SHOWMSG)
		std::cout << COLOR("AMateria assignation operator called.", GREEN) << std::endl;

	return *this;
}

AMateria::~AMateria(void) {

	if (SHOWMSG)
		std::cout << COLOR("AMateria destructor called.", RED) << std::endl;
}

/* ************************************************************************** */
/*                           PARAMETRIC CONSTRUCTOR                           */
/* ************************************************************************** */

AMateria::AMateria(std::string const & type) : _type(type) {

	if (SHOWMSG)
		std::cout << COLOR("AMateria Parametric constructor called.", GREEN) << std::endl;
}

/* ************************************************************************** */
/*                                   GETTER                                   */
/* ************************************************************************** */

std::string const & AMateria::getType(void) const {

	return (this->_type);
}

/* ************************************************************************** */
/*                              MEMBER FUNCTIONS                             */
/* ************************************************************************** */

/*
	No implementation of clone() since it's a virtual pure function
*/

void AMateria::use(ICharacter& target) {

	std::cout << COLOR(_type, MAGENTA) << COLOR("* used a function from a non-existing AMateria at ", RED) << \
		COLOR(target.getName(), MAGENTA) << COLOR(" *", RED) << std::endl;
}
