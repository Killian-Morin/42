/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:45:36 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/29 13:36:03 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedPointValue(0)
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

	this->_fixedPointValue = other.getRawBits();
}

Fixed& Fixed::operator=(Fixed& rhs)
{
	std::cout << CYAN << "Copy assignment operator called" << WHITE << std::endl;

	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();

	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << MAGENTA << "getRawBits member function called" << WHITE << std::endl;

	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << MAGENTA << "setRawBits member function called" << WHITE << std::endl;

	this->_fixedPointValue = raw;
}
