/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:23:56 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/28 13:55:14 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	// std::cout << GREEN << "Default constructor called" << WHITE << std::endl;
}

Point::~Point()
{
	// std::cout << RED << "Destructor called" << WHITE << std::endl;
}

Point::Point(const Point &other) : _x(other._x), _y(other._y)
{
	// std::cout << BLUE << "Copy constructor called" << WHITE << std::endl;
}

Point&	Point::operator=(const Point& other)
{
	// Check for self-assignment
	if (this != &other)
	{
		// Copy values from 'other' to 'this'
		(Fixed)this->_x = other._x;
		(Fixed)this->_y = other._y;
	}
	return *this;
}

Point::Point(const float xValue, const float yValue) : _x(xValue), _y(yValue)
{
	// std::cout << BLUE << "Constructor with parameters called" << WHITE << std::endl;
}

const Fixed&	Point::getX() const
{
	return (_x);
}

const Fixed&	Point::getY() const
{
	return (_y);
}
