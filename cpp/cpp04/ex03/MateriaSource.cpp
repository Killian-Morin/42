/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:28:49 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/05 17:02:39 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << COLOR("MateriaSource default constructor called.", BLUE) << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	*this = src;
	std::cout << COLOR("MateriaSource copy constructor called.", BLUE) << std::endl;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& rhs)
{
	if (this != &rhs)
	{
		// Do the assignment here
	}
	std::cout << COLOR("MateriaSource assignation operator called.", BLUE) << std::endl;
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	std::cout << COLOR("MateriaSource default destructor called.", RED) << std::endl;
}

void	MateriaSource::learnMateria(AMateria*)
{

}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	
}
