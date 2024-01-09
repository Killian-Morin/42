/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:23:54 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 11:09:35 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void) {

	Point const	a(0, 0);
	Point const	b(10, 30);
	Point const	c(20, 0);

	Point const	p(5, 5);

	if (bsp(a, b, c, p) == true)
		std::cout << CYAN << "The point is inside the triangle." << WHITE << std::endl;
	else
		std::cout << MAGENTA << "The point is outside the triangle." << WHITE << std::endl;

	return (0);
}
