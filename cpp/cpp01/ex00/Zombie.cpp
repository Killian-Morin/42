/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:04:14 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/05 15:27:57 by kmorin           ###   ########.fr       */
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

// default constructor
Zombie::Zombie(void)
{
	std::cout << COLOR("Default constructor called", GREEN) << WHITE << std::endl;
}
