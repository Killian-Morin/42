/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:45:57 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/23 16:45:59 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed() : _value(0)
{
	std::cout << GREEN << "Default constructor called" << WHITE << std::endl;
}

Fixed::~Fixed()
{
	std::cout << RED << "Destructor called" << WHITE << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << BLUE << "Copy constructor called" << WHITE << std::endl;

	this->_value = other.getRawBits();
}

Fixed& Fixed::operator=(Fixed& rhs)
{
	std::cout << CYAN << "Copy assignment operator called" << WHITE << std::endl;

	this->_value = rhs.getRawBits();

	return *this;
}

int	Fixed::getRawBits(void) const
{
	std::cout << MAGENTA << "getRawBits member function called" << WHITE << std::endl;

	return this->_value;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << MAGENTA << "setRawBits member function called" << WHITE << std::endl;

	this->_value = raw;
}
