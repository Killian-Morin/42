/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:23:58 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/29 13:59:25 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cstdlib>

class Point
{
	public:
		Point();
		~Point();

		Point(const Point &other);//copy constructor
		Point &operator=(const Point &other);//assignment operator overload

		Point(const float xValue, const float yValue);//constructor with parameters

		// Getter functions for x and y
		Fixed const	getX() const;
		Fixed const	getY() const;

	private:
		Fixed const	_x;
		Fixed const	_y;
};

bool bsp(Point const a, Point const b, Point const c, Point const p);
