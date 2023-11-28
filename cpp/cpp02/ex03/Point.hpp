/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:23:58 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/28 16:14:57 by kmorin           ###   ########.fr       */
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
		const Fixed	&getX() const;
		const Fixed	&getY() const;

	private:
		const Fixed	_x;
		const Fixed	_y;
};

bool bsp(Point const a, Point const b, Point const c, Point const p);
