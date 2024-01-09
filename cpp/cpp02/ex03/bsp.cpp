/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:23:47 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 11:11:37 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	abs(Fixed i) {

	if (i < 0)
		return (i * -1);
	return (i);
}

/*
	Solution by comparing the area of the triangle (with all 3 summits)
	and the sum of the area of the 3 triangle formed with the points and the 3 summits
*/
Fixed area(Point const a, Point const b, Point const c) {

	return (((a.getX()*(b.getY() - c.getY())) + (b.getX()*(c.getY() - a.getY())) + (c.getX()*(a.getY() - b.getY()))) / 2);
}

bool	bsp(Point const a, Point const b, Point const c, Point const p) {

	Fixed	a1 = abs(area(a, b, p));
	Fixed	a2 = abs(area(b, c, p));
	Fixed	a3 = abs(area(a, c, p));
	Fixed	total = abs(area(a, b, c));

	if (a1 == 0 || a2 == 0 || a3 == 0)
		return (false);
	if (total == a1 + a2 + a3)
		return (true);
	return (false);
}
