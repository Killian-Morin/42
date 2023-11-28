/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:45:57 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/28 13:42:29 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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

Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout << CYAN << "Copy assignment operator called" << WHITE << std::endl;

	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();

	return (*this);
}

int	Fixed::getRawBits(void) const
{
	// std::cout << MAGENTA << "getRawBits member function called" << WHITE << std::endl;

	return this->_fixedPointValue;
}

void	Fixed::setRawBits(const int raw)
{
	// std::cout << MAGENTA << "setRawBits member function called" << WHITE << std::endl;

	this->_fixedPointValue = raw;
}

Fixed::Fixed(const int n) : _fixedPointValue(n << _fractionalBits)
{
	std::cout << YELLOW << "Int constructor called" << WHITE << std::endl;
}

Fixed::Fixed(const float n) : _fixedPointValue(std::roundf(n * (1 << _fractionalBits)))
{
	std::cout << YELLOW << "Float constructor called" << WHITE << std::endl;
}

int	Fixed::toInt(void) const
{
	return (this->getRawBits() >> _fractionalBits);
}

float	Fixed::toFloat(void) const
{
	return (std::roundf(this->getRawBits()) / (1 << _fractionalBits));
}

std::ostream&	operator<<(std::ostream& o, Fixed const& instance)
{
	o << instance.toFloat();
	return (o);
}
