/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:01:34 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/05 16:19:39 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	std::cout << COLOR("AMateria default constructor called.", BLUE) << std::endl;
}

AMateria::AMateria(const AMateria &src)
{
	*this = src;
	std::cout << COLOR("AMateria copy constructor called.", BLUE) << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	std::cout << COLOR("AMateria parametric constructor called.", BLUE) << std::endl;
}

AMateria& AMateria::operator=(const AMateria &rhs)
{
	if (this != &rhs)
	{
		// Do the assignment here
	}
	std::cout << COLOR("AMateria assignation operator called.", BLUE) << std::endl;
	return *this;
}

AMateria::~AMateria(void)
{
	std::cout << COLOR("AMateria destructor called.", RED) << std::endl;
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	// std::cout << COLOR("AMateria use function called.", GREEN) << std::endl;
}
