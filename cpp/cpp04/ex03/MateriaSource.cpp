/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:28:49 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/06 15:32:16 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/* ************************************************************************** */
/*                  CANONIC METHODS and SPECIAL CONSTRUCTORS                  */
/* ************************************************************************** */

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->materias[i] = NULL;
	std::cout << COLOR("MateriaSource default constructor called.", BLUE) << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	for (int i = 0; i < 4; i++)
		this->materias[i] = src.materias[i];
	std::cout << COLOR("MateriaSource copy constructor called.", BLUE) << std::endl;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
			this->materias[i] = rhs.materias[i];
	}
	std::cout << COLOR("MateriaSource assignation operator called.", BLUE) << std::endl;
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materias[i])
			delete this->materias[i];
		this->materias[i] = NULL;
	}
	std::cout << COLOR("MateriaSource default destructor called.", RED) << std::endl;
}

/* ************************************************************************** */
/*                              MEMBERS FUNCTIONS                             */
/* ************************************************************************** */

void	MateriaSource::learnMateria(AMateria*)
{

}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	if (type != "ice" || type != "cure")
		return (0);
	return (0);
}
