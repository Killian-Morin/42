/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:53:27 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/22 13:59:20 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#define GREEN "\e[0;32m"
#define WHITE "\033[37m"

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";

	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "memory address of string: " << GREEN << &string << WHITE << std::endl;
	std::cout << "memory address of stringPTR: " << GREEN << &stringPTR << WHITE << std::endl;
	std::cout << "memory address of stringREF: " << GREEN << &stringREF << WHITE << std::endl << std::endl;

	std::cout << "value of string: " << GREEN << string << WHITE << std::endl;
	std::cout << "value of stringPTR: " << GREEN << stringPTR << WHITE << std::endl;
	std::cout << "value of stringREF: " << GREEN << stringREF << WHITE << std::endl;

	return (0);
}
