/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:31:07 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/21 15:58:45 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl default constructor" << std::endl << std::endl;
}

Harl::~Harl()
{
	std::cout << std::endl << "Harl default destructor" << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	type[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

}

void	Harl::debug(void)
{
	std::cout << GREEN << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << WHITE << std::endl;
}

void	Harl::info(void)
{
	std::cout << BLUE << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << WHITE << std::endl;
}

void	Harl::warning(void)
{
	std::cout << MAGENTA << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << WHITE << std::endl;
}

void	Harl::error(void)
{
	std::cout << CYAN << "This is unacceptable! I want to speak to the manager now." << WHITE << std::endl;
}
