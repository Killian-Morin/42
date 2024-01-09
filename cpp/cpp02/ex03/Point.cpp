/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:23:56 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 11:20:47 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

Point::Point(void) : _x(0), _y(0) {

	if (SHOWMSG)
		std::cout << COLOR("Point", GREENULINE) << COLOR(" Default constructor called", GREEN) << std::endl;
}

Point::Point(const Point &src) : _x(src._x), _y(src._y) {

	if (SHOWMSG)
		std::cout << COLOR("Point", GREENULINE) << COLOR(" Copy constructor called", GREEN) << std::endl;
}

Point&	Point::operator=(const Point& rhs) {

	if (this != &rhs) {
		(Fixed)this->_x = rhs._x;
		(Fixed)this->_y = rhs._y;
	}

	if (SHOWMSG)
		std::cout << COLOR("Point", GREENULINE) << COLOR(" Copy assignment operator called", GREEN) << std::endl;

	return (*this);
}

Point::~Point(void) {

	if (SHOWMSG)
		std::cout << COLOR("Point", REDULINE) << COLOR(" Default destructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                          PARAMETRIC CONSTRUCTOR                            */
/* ************************************************************************** */

Point::Point(const float xValue, const float yValue) : _x(xValue), _y(yValue) {

	if (SHOWMSG)
		std::cout << COLOR("Point", GREENULINE) << COLOR(" Parametric constructor called", BOLDGREEN) << std::endl;
}

/* ************************************************************************** */
/*                                   GETTERS                                  */
/* ************************************************************************** */

Fixed const	Point::getX() const {

	return (this->_x);
}

Fixed const	Point::getY() const {

	return (this->_y);
}
