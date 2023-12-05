/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:17:03 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/05 15:31:47 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string tmp) : _name(tmp)
{
	std::cout << CYAN << "Zombie " << this->_name << " has been created" << WHITE << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << RED << "Zombie " << this->_name << " has been destroyed" << WHITE << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << YELLOW << "Zombie " << this->_name << ": BraiiiiiiinnnzzzZ..." << WHITE << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

// default constructor
//since this->name has not yet been defined the var prints nothing (but the line still work)
Zombie::Zombie(void)
{
	std::cout << COLOR("Default constructor called", GREEN) << WHITE << std::endl;
}
