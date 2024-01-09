/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:37:59 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/08 15:42:41 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

/*
PHONEBOOK DISPLAY FORMAT
/-------------------------------------------\
|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|
|0123456789|0123456789|0123456789|0123456789|
|----------|----------|----------|----------|
|----------|----------|----------|----------|
|----------|----------|----------|----------|
\-------------------------------------------/
*/

int	main(void) {

	PhoneBook	phonebook;

	std::string	input;
	while (1) {

		std::cout << COLOR("Enter a command [ADD, SEARCH, EXIT]", BLUE) << std::endl << "> ";
		std::cin >> input;

		phonebook.handleCtrlD();

		if (input == "ADD") {
			phonebook.add();

			std::cin.clear();
		}
		else if (input == "SEARCH") {
			phonebook.search();

			std::cin.clear();
			std::cin.ignore();
		}
		else if (input == "EXIT") {
			std::cout << std::endl << COLOR("Exit the phonebook.\nBye !", MAGENTA) << std::endl;
			break ;
		}
		else {
			std::cout << COLOR("Invalid Command ! Try again.", RED) << std::endl;
			std::cin.clear();
		}

		phonebook.handleCtrlD();

		std::cout << std::endl;
	}

	return (0);
}
