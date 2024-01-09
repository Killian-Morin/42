/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:53:31 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 16:03:31 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void) {

	std::cout << std::endl;

	/*	INT ARRAY	*/
	std::cout << GREEN << "INT:" << std::endl;
	int	arrayInt[5] = {1, 2, 3, 4, 5};
	::iter(arrayInt, 5, print);
	std::cout << RESET << std::endl;

	/*	CHAR ARRAY	*/
	std::cout << MAGENTA "CHAR:" << std::endl;
	char	arrayChar[5] = {'a', 'b', 'c', 'd', 'e'};
	::iter(arrayChar, 5, print);
	std::cout << RESET << std::endl;

	/*	DOUBLE ARRAY	*/
	std::cout << YELLOW << "DOUBLE:" << std::endl;
	double	arrayDouble[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	::iter(arrayDouble, 5, print);
	std::cout << RESET << std::endl;

	/*	STRING ARRAY	*/
	std::cout << CYAN << "STRING:" << std::endl;
	std::string	arrayString[5] = {"Hello", "There", "", "General", "Kenobi"};
	::iter(arrayString, 5, print);
	std::cout << RESET << std::endl;

	return (0);
}
