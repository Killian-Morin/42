/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:45:57 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 10:58:20 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

Fixed::Fixed(void) : _fixedPointValue(0) {

	if (SHOWMSG)
		std::cout << COLOR("Default constructor called", GREEN) << std::endl;
}

Fixed::Fixed(const Fixed& src) {

	if (SHOWMSG)
		std::cout << COLOR("Copy constructor called", GREEN) << std::endl;

	this->_fixedPointValue = src.getRawBits();
	// *this = src;
}

Fixed& Fixed::operator=(const Fixed& rhs) {

	if (SHOWMSG)
		std::cout << COLOR("Copy assignment operator called", GREEN) << std::endl;

	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();

	return (*this);
}

Fixed::~Fixed(void) {

	if (SHOWMSG)
		std::cout << COLOR("Default destructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                                GETTER/SETTER                               */
/* ************************************************************************** */

int	Fixed::getRawBits(void) const {

	// if (SHOWMSG)
		// std::cout << COLOR("getRawBits member function called", MAGENTA) << std::endl;

	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const raw) {

	// if (SHOWMSG)
		// std::cout << COLOR("setRawBits member function called", MAGENTA) << std::endl;

	this->_fixedPointValue = raw;
}

/* ************************************************************************** */
/*                          PARAMETRIC CONSTRUCTORS                           */
/* ************************************************************************** */

Fixed::Fixed(const int n) : _fixedPointValue(n << _fractionalBits) {

	if (SHOWMSG)
		std::cout << COLOR("Int constructor called", BOLDGREEN) << std::endl;
}

Fixed::Fixed(const float n) : _fixedPointValue(std::roundf(n * (1 << _fractionalBits))) {

	if (SHOWMSG)
		std::cout << COLOR("Float constructor called", BOLDGREEN) << std::endl;
}

/* ************************************************************************** */
/*                               MEMBER FUNCTIONS                             */
/* ************************************************************************** */

int	Fixed::toInt(void) const {

	return (this->getRawBits() >> _fractionalBits);
}

float	Fixed::toFloat(void) const {

	return (std::roundf(this->getRawBits()) / (1 << _fractionalBits));
}

/* ************************************************************************** */
/*                             EXTERNAL FUNCTIONS                             */
/* ************************************************************************** */

std::ostream&	operator<<(std::ostream& o, Fixed const& instance) {

	o << instance.toFloat();
	return (o);
}
