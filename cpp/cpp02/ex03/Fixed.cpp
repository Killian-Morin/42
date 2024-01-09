/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:23:49 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 11:19:23 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

Fixed::Fixed(void) : _fixedPointValue(0) {

	if (SHOWMSG)
		std::cout << COLOR("Fixed", GREENULINE) << COLOR(" Default constructor called", GREEN) << std::endl;
}

Fixed::Fixed(const Fixed& src) {

	if (SHOWMSG)
		std::cout << COLOR("Fixed", GREENULINE) << COLOR(" Copy constructor called", GREEN) << std::endl;

	this->_fixedPointValue = src.getRawBits();
	// *this = src;
}

Fixed& Fixed::operator=(const Fixed& rhs) {

	if (SHOWMSG)
		std::cout << COLOR("Fixed", GREENULINE) << COLOR(" Copy assignment operator called", GREEN) << std::endl;

	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();

	return (*this);
}

Fixed::~Fixed(void) {

	if (SHOWMSG)
		std::cout << COLOR("Fixed", REDULINE) << COLOR(" Default destructor called", RED) << std::endl;
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
		std::cout << COLOR("Fixed", GREENULINE) << COLOR(" Int constructor called", BOLDGREEN) << std::endl;
}

Fixed::Fixed(const float n) : _fixedPointValue(std::roundf(n * (1 << _fractionalBits))) {

	if (SHOWMSG)
		std::cout << COLOR("Fixed", GREENULINE) << COLOR(" Float constructor called", BOLDGREEN) << std::endl;
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

bool	Fixed::operator>(const Fixed& rhs) const {

	if (this->_fixedPointValue > rhs._fixedPointValue)
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed& rhs) const {

	if (this->_fixedPointValue < rhs._fixedPointValue)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed& rhs) const {

	if (this->_fixedPointValue >= rhs._fixedPointValue)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed& rhs) const {

	if (this->_fixedPointValue <= rhs._fixedPointValue)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed& rhs) const {

	if (this->_fixedPointValue == rhs._fixedPointValue)
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed& rhs) const {

	if (this->_fixedPointValue != rhs._fixedPointValue)
		return (true);
	return (false);
}

Fixed	Fixed::operator+(const Fixed& rhs) const {

	Fixed	tmp(this->toFloat() + rhs.toFloat());

	return (tmp);
}

Fixed	Fixed::operator-(const Fixed& rhs) const {

	Fixed	tmp(this->toFloat() - rhs.toFloat());

	return (tmp);
}

Fixed	Fixed::operator*(const Fixed& rhs) const {

	Fixed	tmp(this->toFloat() * rhs.toFloat());

	return (tmp);
}

Fixed	Fixed::operator/(const Fixed& rhs) const {

	if (rhs._fixedPointValue != 0) {
		Fixed	tmp(this->toFloat() / rhs.toFloat());
		return (tmp);
	}
	else {
		Fixed	tmp;
		std::cout << RED << "Error: division by ";
		return (tmp);
	}
}

Fixed&	Fixed::operator++(void) {

	this->_fixedPointValue++;
	return (*this);
}

Fixed	Fixed::operator++(int) {

	Fixed	tmp(*this);

	operator++();

	return (tmp);
}

Fixed&	Fixed::operator--(void) {

	this->_fixedPointValue--;
	return (*this);
}

Fixed	Fixed::operator--(int) {

	Fixed	tmp(*this);

	operator--();

	return (tmp);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b) {

	std::cout << "Used the non-const version of min" << std::endl;
	std::cout << "    result: ";
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return (a);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {

	std::cout << "Used the const version of min" << std::endl;
	std::cout << "    result: ";
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return (a);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {

	std::cout << "Used the non-const version of max" << std::endl;
	std::cout << "    result: ";
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {

	std::cout << "Used the const version of max" << std::endl;
	std::cout << "    result: ";
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

/* ************************************************************************** */
/*                             EXTERNAL FUNCTIONS                             */
/* ************************************************************************** */

std::ostream&	operator<<(std::ostream& o, Fixed const& instance) {
	o << instance.toFloat();
	return (o);
}
