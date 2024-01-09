/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:23:58 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 11:15:54 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

#include <cstdlib>

class Point {

	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		//Canonical class functions
		Point(void);
		Point(const Point &src);
		Point &operator=(const Point &rhs);
		~Point(void);

		//Parametric constructor
		Point(const float xValue, const float yValue);

		//Getters
		Fixed const	getX() const;
		Fixed const	getY() const;
};

//External Functions (in bcp.cpp)
bool bsp(Point const a, Point const b, Point const c, Point const p);

#endif //POINT_HPP
