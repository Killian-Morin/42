/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:37:59 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/02 15:30:19 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook[8];

	std::string	input;
	do
	{
		std::cout << "Enter a command [ADD, SEARCH, EXIT]" << std::endl << "> ";
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			std::cout << "add" << std::endl;
		}
		else if (input == "SEARCH")
		{
			std::cout << "search" << std::endl;
		}
		else if (input == "EXIT")
		{
			std::cout << "Bye !" << std::endl;
			return (0);
		}
		else
			std::cout << "Invalid Command ! Try again." << std::endl;
	} while (input != "EXIT" && std::cin.eof());
	return (0);
}
