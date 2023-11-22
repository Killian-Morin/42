/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:07:53 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/22 14:33:05 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	// std::cout << "Harl default constructor" << std::endl << std::endl;
}

Harl::~Harl()
{
	// std::cout << std::endl << "Harl default destructor" << std::endl;
}

void	Harl::exitHandler(std::string level) const
{
	if (level == "EXIT" || level == "exit")
	{
		std::cout << RED << std::endl << "Exit Harl filter." << WHITE << std::endl;
		exit(0);
	}

	if (std::cin.eof())
	{
		std::cout << RED << std::endl << "Exit Harl filter with ^D." << WHITE << std::endl;
		exit (0);
	}
}

void	Harl::complain(std::string level)
{
	//array of strings with the valid levels
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	//declaring the array of pointers to members methods
	//the '&' to have the pointer to the method
	void (Harl::*methods[])(void) = {
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error
	};

	//iterate max 4 times since 4 valid level
	//if the input correspond to a valid level
	//	break the loop to stop iterating the index at which we will start
	//if the input does not correspond to a valid level
	//	will go in the default in the switch loop to print an appropriate message
	int	i = 0;
	while (i < 4)
	{
		if (level == levels[i])
			break;
		i++;
	}

	//break only for the last case since we don't want to print the default
	//and we called all methods below the valid one
	switch (i)
	{
		case 0:
			(this->*methods[i++])();

		case 1:
			(this->*methods[i++])();

		case 2:
			(this->*methods[i++])();

		case 3:
			(this->*methods[i])();
			break;

		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl << std::endl;
			break;
	}
}

void	Harl::_debug(void)
{
	std::cout << GREEN << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I really do!" << WHITE << std::endl << std::endl;
}

void	Harl::_info(void)
{
	std::cout << BLUE << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn't put enough bacon in my burger!" << std::endl;
	std::cout << "If you did, I wouldn't be asking for more!" << WHITE << std::endl << std::endl;
}

void	Harl::_warning(void)
{
	std::cout << MAGENTA << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years whereas you started working here since last month." << WHITE << std::endl << std::endl;
}

void	Harl::_error(void)
{
	std::cout << CYAN << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << WHITE << std::endl << std::endl;
}
