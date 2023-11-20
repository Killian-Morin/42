/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:17:03 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/20 15:52:11 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string tmp) : _name(tmp)
{
	std::cout << CYAN << "Zombie " << this->_name << " has been created" << WHITE << std::endl;
}

Zombie::~Zombie()
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
Zombie::Zombie()
{
}
