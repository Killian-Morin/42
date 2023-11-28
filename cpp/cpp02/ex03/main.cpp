/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:23:54 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/28 17:59:34 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	Point const	a(1, 1);
	Point const	b(3, 4);
	Point const	c(5, 1);

	Point const	p(5, 1);

	if (bsp(a, b, c, p) == true)
		std::cout << CYAN << "The point is inside the triangle." << WHITE << std::endl;
	else
		std::cout << MAGENTA << "The point is outside the triangle." << WHITE << std::endl;

	return (0);
}
