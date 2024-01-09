/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:28:49 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:36:35 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

MateriaSource::MateriaSource(void) : _idxMaterias(0) {

	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;

	if (SHOWMSG)
	std::cout << COLOR("MateriaSource default constructor called.", GREEN) << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& src) : _idxMaterias(src._idxMaterias) {

	for (int i = 0; i < 4; i++)
		this->_materias[i] = src._materias[i];

	if (SHOWMSG)
		std::cout << COLOR("MateriaSource copy constructor called.", GREEN) << std::endl;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& rhs) {

	if (this != &rhs) {
		for (int i = 0; i < 4; i++)
			this->_materias[i] = rhs._materias[i];

		this->_idxMaterias = rhs._idxMaterias;
	}

	if (SHOWMSG)
		std::cout << COLOR("MateriaSource assignation operator called.", GREEN) << std::endl;

	return (*this);
}

MateriaSource::~MateriaSource(void) {

	for (int i = 0; i < 4; i++) {
		if (this->_materias[i])
			delete this->_materias[i];
		this->_materias[i] = NULL;
	}

	if (SHOWMSG)
		std::cout << COLOR("MateriaSource default destructor called.", RED) << std::endl;
}

/* ************************************************************************** */
/*                        OVERLOADED HERITED FUNCTIONS                        */
/* ************************************************************************** */

/*
Copies the Materia passed as a parameter and store it in memory so it can be cloned later.
Like the Character, the MateriaSource can know at most 4 Materias. They are not necessarily unique.
*/
void	MateriaSource::learnMateria(AMateria* m) {

	if (this->_idxMaterias == 4) {
		std::cout << "❌ " << COLOR("MateriaSource:", YELLOWULINE) << COLOR(" is full.", RED) << std::endl;

		delete this->_materias[0];
		for (int i = 0; i < this->_idxMaterias - 1; i++)
			this->_materias[i] = this->_materias[i + 1];
		std::cout << COLOR("Oh, we suddenly forget the oldest Materia learned, now we can learn a new one.", YELLOW) << std::endl;

		this->_materias[this->_idxMaterias - 1] = m;
		std::cout << COLOR("MateriaSource:", YELLOWULINE) << " " << \
			COLOR(this->_materias[this->_idxMaterias - 1]->getType(), MAGENTA) << COLOR(" has been learned.", YELLOW) << std::endl;
	}
	else {
		this->_materias[this->_idxMaterias] = m;
		this->_idxMaterias++;

		std::cout << "🎉 " << COLOR("MateriaSource:", YELLOWULINE) << " " << \
			COLOR(this->_materias[this->_idxMaterias - 1]->getType(), MAGENTA) << COLOR(" has been learned.", YELLOW) << std::endl;
	}
}

/*
Returns a new Materia. The latter is a copy of the Materia previously learned by
the MateriaSource whose type equals the one passed as parameter. Returns 0 if the type is unknown.
*/
AMateria*	MateriaSource::createMateria(std::string const& type) {

	for (int i = 0; i < this->_idxMaterias; i++) {
		if (this->_materias[i]->getType() == type)
			return (this->_materias[i]->clone());
	}
	return (0);
}

/* ************************************************************************** */
/*                               EXTRA FUNCTION                               */
/* ************************************************************************** */

void	MateriaSource::displayMateriasLearned(void) const {

	if (this->_idxMaterias == 0)
		std::cout << "❌ " << COLOR("MateriaSource:", YELLOWULINE) << " " << \
			COLOR("hasn't learned any Materias yet.", YELLOW) << std::endl;
	else
		std::cout << "🎉 " << COLOR("MateriaSource:", YELLOWULINE) << " " << \
			COLOR("the Materias learned are: ", YELLOW) << std::endl;
	for (int i = 0; i < this->_idxMaterias; i++) {
		std::cout << COLOR(this->_materias[i]->getType(), MAGENTA);
		if (i < this->_idxMaterias - 1)
			std::cout << COLOR(", ", YELLOW);
	}
}
