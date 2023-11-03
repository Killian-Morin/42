/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:37:59 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/03 18:06:57 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

/*
PHONEBOOK DISPLAY FORMAT
/-------------------------------------------\
|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|
|----------|----------|----------|----------|
|----------|----------|----------|----------|
|----------|----------|----------|----------|
\-------------------------------------------/
*/

int	main(void)
{
	PhoneBook	phonebook;

	std::string	input;
	phonebook.set_NbContact(-1);
	do
	{
		std::cout << "Enter a command [ADD, SEARCH, EXIT]" << std::endl << "> ";
		std::getline(std::cin, input);
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
			std::cout << "Bye !" << std::endl;
			return (0);
		}
		else
		{
			std::cout << "Invalid Command ! Try again." << std::endl;
			std::cin.clear();
		}
	} while (input != "EXIT" && !std::cin.eof());
	return (0);
}
