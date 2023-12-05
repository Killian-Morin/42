/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:28:45 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/05 16:30:25 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("Cure")
{
	std::cout << COLOR("Cure default constructor called.", BLUE) << std::endl;
}

Cure::Cure(const Cure &src)
{
	*this = src;
	std::cout << COLOR("Cure copy constructor called.", BLUE) << std::endl;
}

Cure& Cure::operator=(const Cure &rhs)
{
	if (this != &rhs)
	{
		// Do the assignment here
	}
	std::cout << COLOR("Cure assignation operator called.", BLUE) << std::endl;
	return *this;
}

Cure::~Cure(void)
{
	std::cout << COLOR("Cure destructor called.", RED) << std::endl;
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << COLOR("* heals " << target.getName() << "'s wounds *", GREEN) << std::endl;
}
