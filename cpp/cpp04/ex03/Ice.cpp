/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:28:44 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/05 16:34:26 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void)
{
	std::cout << COLOR("Ice default constructor called.", BLUE) << std::endl;
}

Ice::Ice(const Ice &src)
{
	*this = src;
	std::cout << COLOR("Ice copy constructor called.", BLUE) << std::endl;
}

Ice& Ice::operator=(const Ice &rhs)
{
	if (this != &rhs)
	{
		// Do the assignment here
	}
	std::cout << COLOR("Ice assignation operator called.", BLUE) << std::endl;
	return *this;
}

Ice::~Ice(void)
{
	std::cout << COLOR("Ice destructor called.", RED) << std::endl;
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << COLOR("* shoots an ice bolt at " << target.getName() << " *", GREEN) << std::endl;
}
