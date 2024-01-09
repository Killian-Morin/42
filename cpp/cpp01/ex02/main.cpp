/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:53:27 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 09:24:39 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#define RESET "\e[0m"
#define GREEN "\e[0;32m"

#define COLOR(text, color) color << text << RESET

int	main(void) {

	std::string	string = "HI THIS IS BRAIN";

	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "memory address of string: " << COLOR(&string, GREEN) << std::endl;
	std::cout << "memory address of stringPTR: " << COLOR(&stringPTR, GREEN) << std::endl;
	std::cout << "memory address of stringREF: " << GREEN << COLOR(&stringREF, GREEN) << std::endl << std::endl;

	std::cout << "value of string: " << COLOR(string, GREEN) << std::endl;
	std::cout << "value of stringPTR: " << COLOR(stringPTR, GREEN) << std::endl;
	std::cout << "value of stringREF: " << COLOR(stringREF, GREEN) << std::endl;

	return (0);
}
