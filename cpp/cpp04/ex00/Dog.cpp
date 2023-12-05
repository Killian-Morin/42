/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:58:24 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/05 11:13:59 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	this->_type = "Dog";
	std::cout << COLOR("Dog 🐶", YELLOW);
	std::cout << COLOR(" Default constructor", BLUE) << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src)
{
	std::cout << COLOR("Dog 🐶", YELLOW);
	std::cout << COLOR(" Copy constructor", BLUE) << std::endl;
}

Dog&	Dog::operator=(const Dog& rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	std::cout << COLOR("Dog 🐶", YELLOW);
	std::cout << COLOR(" assignement operator called", BLUE) << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << COLOR("Dog 🐶", YELLOW);
	std::cout << COLOR(" Default destructor", RED) << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << COLOR("Dog 🐶", YELLOW);
	std::cout << COLOR(" makes a sound: bark 🐶", MAGENTA) << std::endl;
}
