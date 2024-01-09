/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:41:14 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:59:52 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

/*
	Since Serializer has to be non-instanciable,
	all its canonical functions are in private,
	with no message in them since we can nothing with the class apart from
	calling the static member function convert.
*/
Serializer::Serializer(void) {

	if (SHOWMSG)
		std::cout << COLOR("Serializer ", BLUE) << COLOR("Default constructor called", GREEN) << std::endl;
}

Serializer::Serializer(const Serializer& src) {

	*this = src;

	if (SHOWMSG)
		std::cout << COLOR("Serializer ", BLUE) << COLOR("Copy constructor called", GREEN) << std::endl;
}

Serializer&	Serializer::operator=(const Serializer& rhs) {

	(void)rhs;

	if (SHOWMSG)
		std::cout << COLOR("Serializer ", BLUE) << COLOR("Assignation operator called", GREEN) << std::endl;

	return (*this);
}

Serializer::~Serializer(void) {

	if (SHOWMSG)
		std::cout << COLOR("Serializer ", BLUE) << COLOR("Default destructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                              MEMBER FUNCTIONS                             */
/* ************************************************************************** */

uintptr_t	Serializer::serialize(Data* ptr) {

	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw) {

	return (reinterpret_cast<Data *>(raw));
}
