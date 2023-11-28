/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:23:47 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/28 17:57:28 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	abs(Fixed i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

/*
	Solution by comparing the area of the triangle (with all 3 summits)
	and the sum of the area of the 3 triangle formed with the points and the 3 summits
*/
Fixed area(Point const a, Point const b, Point const c)
{
	return ((a.getX()*(b.getY() - c.getY()) + b.getX()*(c.getY() - a.getY()) + c.getX()*(a.getY() - b.getY())) / (float)2.0);
}

bool	bsp(Point const a, Point const b, Point const c, Point const p)
{
	Fixed	a1 = abs(area(a, b, p));
	Fixed	a2 = abs(area(a, c, p));
	Fixed	a3 = abs(area(b, c, p));
	Fixed	total = abs(area(a, b, c));

	if (total == a1 + a2 + a3)
		return (true);
	else if (a1 == 0 || a2 == 0 || a3 == 0)
		std::cout << YELLOW << "The point is on the edge or on one of the summit of the triangle." << std::endl;
	return (false);
}

/*
	Solution using Barycentric Coordinate Method
	pas fini
*/
/*
bool	bsp(Point const a, Point const b, Point const c, Point const p)
{
	Fixed	denominator = ((b.getY() - c.getY()) * (a.getX() - c.getX()) + (c.getX() - b.getX()) * (a.getY() - c.getY()));

	Fixed	a = ((b.getY() - c.getY()) * (p.getX() - c.getX()) + (c.getX() - b.getX()) * (p.getY() - c.getY())) / denominator;
	Fixed	b = ((c.getY() - a.getY()) * (p.getX() - c.getX()) + (a.getX() - c.getX()) * (p.getY() - a.getY())) / denominator;
	Fixed	c = 1 - a - b;

	Fixed	tmp;
	if (a >= tmp && b >= tmp && c >= tmp)
		return (true);
	else
		return (false);
}*/
