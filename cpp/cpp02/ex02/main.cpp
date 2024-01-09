/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 08:37:15 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 11:07:45 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {

	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << YELLOW << "COMPARISON OPERATORS (>, <, >=, <=, == and !=):" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	if (a.operator>(b))
		std::cout << "a is greater than b (true)" << std::endl;
	else
		std::cout << "b is greater than a (false)" << std::endl;
	if (a.operator<(b) == true)
		std::cout << "a is smaller than b (true)" << std::endl;
	else
		std::cout << "b is smaller than a (false)" << std::endl;
	if (a.operator>=(b))
		std::cout << "a is greater or equal than b (true)" << std::endl;
	else
		std::cout << "b is greater or equal than a (false)" << std::endl;
	if (a.operator<=(b) == true)
		std::cout << "a is smaller or equal than b (true)" << std::endl;
	else
		std::cout << "b is smaller or equal than a (false)" << std::endl;
	if (a.operator==(b))
		std::cout << "a is equal to b (true)" << std::endl;
	else
		std::cout << "a is not equal to b (false)" << std::endl;
	if (a.operator!=(b) == true)
		std::cout << "a is different than b (true)" << std::endl << RESET << std::endl;
	else
		std::cout << "b is not different than a (false)" << std::endl << RESET << std::endl;

	Fixed		c(8);
	Fixed const	d(12);
	std::cout << CYAN << "ARITHMETIC OPERATORS (+, -, *, /):" << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "Addition       = " << c.operator+(d) << std::endl;
	std::cout << "Substraction   = " << c.operator-(d) << std::endl;
	std::cout << "Multiplication = " << c.operator*(d) << std::endl;
	std::cout << "Division       = " << c.operator/(d) << std::endl << std::endl;
	Fixed const	z(0);
	std::cout << "Division      : c = " << c.operator/(z) << std::endl << RESET << std::endl;

	Fixed	e;
	std::cout << BLUE << "INCREMENTATION PRE-FIX AND POST-FIX:" << std::endl;
	std::cout << "e (e)  : " << e << std::endl;
	std::cout << "e (++e): " << ++e << std::endl;
	std::cout << "e (e)  : " << e << std::endl;
	std::cout << "e (e++): " << e++ << std::endl;
	std::cout << "e (e)  : " << e << std::endl << RESET << std::endl;

	Fixed	f;
	std::cout << MAGENTA << "DECREMENTATION PRE-FIX AND POST-FIX:" << std::endl;
	std::cout << "f (f)  : " << f << std::endl;
	std::cout << "f (--f): " << --f << std::endl;
	std::cout << "f (f)  : " << f << std::endl;
	std::cout << "f (f--): " << f-- << std::endl;
	std::cout << "f (f)  : " << f << std::endl << RESET << std::endl;

	Fixed	g(12);
	Fixed	h(32);
	std::cout << GREEN << "MIN AND MAX:" << std::endl;
	std::cout << "g: " << g << std::endl;
	std::cout << "h: " << h << std::endl;
	std::cout << Fixed::max(g, h) << std::endl;
	std::cout << Fixed::min(g, h) << std::endl << std::endl;

	Fixed const	i(40);
	Fixed const	j(32);
	std::cout << GREEN << "MIN AND MAX using the functions with the const parameters and return type:" << std::endl;
	std::cout << "i: " << i << std::endl;
	std::cout << "j: " << j << std::endl;
	std::cout << Fixed::max(i, j) << std::endl;
	std::cout << Fixed::min(i, j) << RESET << std::endl;

	return 0;
}

/*
int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
*/