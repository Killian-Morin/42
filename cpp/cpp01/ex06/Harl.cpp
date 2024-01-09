/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:07:53 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 10:36:38 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/* ************************************************************************** */
/*                           Constructor/Destructor                           */
/* ************************************************************************** */

Harl::Harl(void) {

	if (SHOWMSG)
		std::cout << COLOR("Harl", GREENULINE) << COLOR(" Default constructor called", GREEN) << std::endl;
}

Harl::~Harl(void) {

	if (SHOWMSG)
		std::cout << COLOR("Harl", REDULINE) << COLOR(" Default destructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                             MEMBER FUNCTIONS                               */
/* ************************************************************************** */

bool	Harl::exitHandler(std::string level) const {

	if (level == "exit" || level == "EXIT") {
		std::cout << std::endl << COLOR("Exit Harl.", RED) << std::endl;
		return (false);
	}

	if (std::cin.eof()) {
		std::cout << std::endl << COLOR("Exit Harl with ^D", RED) << std::endl;
		return (false);
	}

	return (true);
}

void	Harl::complain(std::string level) {

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
	while (i < 4) {
		if (level == levels[i])
			break;
		i++;
	}

	//break only for the last case since we don't want to print the default
	//and we called all methods below the valid one
	switch (i) {

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
			std::cout << COLOR("[ Probably complaining about insignificant problems ]", YELLOW) << std::endl << std::endl;
			break;
	}
}

void	Harl::_debug(void) {

	std::cout << GREEN << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I really do!" << RESET << std::endl << std::endl;
}

void	Harl::_info(void) {

	std::cout << BLUE << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn't put enough bacon in my burger!" << std::endl;
	std::cout << "If you did, I wouldn't be asking for more!" << RESET << std::endl << std::endl;
}

void	Harl::_warning(void) {

	std::cout << MAGENTA << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years whereas you started working here since last month." << RESET << std::endl << std::endl;
}

void	Harl::_error(void) {

	std::cout << CYAN << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << RESET << std::endl << std::endl;
}
