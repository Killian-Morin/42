/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:37:59 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/07 13:57:49 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

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

int	main(void)
{
	PhoneBook	phonebook;

	std::string	input;
	while (1)
	{
		std::cout << BLUE << "Enter a command [ADD, SEARCH, EXIT]" << WHITE << std::endl << "> ";
		std::cin >> input;
		phonebook.handleCtrlD();

		if (input == "ADD")
		{
			phonebook.add();
			std::cin.clear();
		}
		else if (input == "SEARCH")
		{
			phonebook.search();
			std::cin.clear();
			std::cin.ignore();
		}
		else if (input == "EXIT")
		{
			std::cout << "Exit the phonebook." << std::endl << "Bye !" << std::endl;
			break ;
		}
		else
		{
			std::cout << RED << "Invalid Command ! Try again." << WHITE << std::endl;
			std::cin.clear();
		}
		phonebook.handleCtrlD();
	}
	return (0);
}
