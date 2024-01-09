/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:52:55 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/05 11:23:05 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

AAnimal::AAnimal(void) : _type("AAnimal_default") {

	if (SHOWMSG)
		std::cout << COLOR("AAnimal", BLUE) << COLOR(" Default constructor called", GREEN) << std::endl;
}

AAnimal::AAnimal(const AAnimal& src) : _type(src._type) {

	if (SHOWMSG)
		std::cout << COLOR("AAnimal", BLUE) << COLOR(" Copy constructor called", GREEN) << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal& rhs) {

	if (this != &rhs)
		this->_type = rhs._type;

	if (SHOWMSG)
		std::cout << COLOR("AAnimal", BLUE) << COLOR(" Assignement operator called", GREEN) << std::endl;

	return (*this);
}

AAnimal::~AAnimal(void) {

	if (SHOWMSG)
		std::cout << COLOR("AAnimal", BLUE) << COLOR(" Default destructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                                   GETTER                                   */
/* ************************************************************************** */

std::string	AAnimal::getType(void) const {
	return (this->_type);
}
