/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:45:36 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 10:47:27 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

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

	if (SHOWMSG)
		std::cout << COLOR("getRawBits member function called", MAGENTA) << std::endl;

	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const raw) {

	if (SHOWMSG)
		std::cout << COLOR("setRawBits member function called", MAGENTA) << std::endl;

	this->_fixedPointValue = raw;
}
