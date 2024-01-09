/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:01:43 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 14:40:16 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main(void) {

	IMateriaSource *src = new MateriaSource();
	std::cout << std::endl;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	// std::cout << std::endl;
	// src->displayMateriasLearned();
	std::cout << std::endl;

	ICharacter *me = new Character("me");
	std::cout << std::endl;

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << std::endl;

	ICharacter *bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	// me->use(2, *bob);

	std::cout << std::endl;
	delete bob;
	std::cout << std::endl;
	delete me;
	std::cout << std::endl;
	delete src;


	/*
	//Rapid test for the use() of Cure and Ice classes
	ICharacter*	joe = new Character("joe");
	std::cout << std::endl;
	Cure*	cure = new Cure();
	Ice*	ice = new Ice();
	std::cout << std::endl;
	cure->use(*joe);
	ice->use(*joe);

	std::cout << std::endl;
	delete joe;
	delete cure;
	delete ice;
	*/

	//PH test
	/*
	//Test for use(), equip() and unequip() with some values > max
	ICharacter *adventurer = new Character("Job");
	for (int i = 0; i < 6; i++)
		adventurer->equip(new Ice());
	std::cout << std::endl;

	std::cout << std::endl;
	for (int i = 0; i < 6; i++)
		adventurer->use(i, *adventurer);
	std::cout << std::endl;

	std::cout << std::endl;
	// adventurer->unequip(1);
	// adventurer->unequip(1);
	for (int i = 0; i < 6; i++)
		adventurer->unequip(i);
	std::cout << std::endl;

	delete adventurer;
	*/

	/*
	//Test for learning a new Materia after reaching the max
	IMateriaSource *book = new MateriaSource();
	for (int i = 0; i < 4; i++)
		book->learnMateria(new Cure());
	std::cout << std::endl;

	book->learnMateria(new Ice());
	std::cout << std::endl;

	delete book;
	*/

	/*
	//Test for some of the Assignement operator and copy constructor
	IMateriaSource *src = new MateriaSource();
	Cure *cure1 = new Cure();
	src->learnMateria(cure1);
	std::cout << std::endl;

	AMateria *tmp, *tmp2;
	tmp = src->createMateria("cure");
	tmp2 = src->createMateria("cure");
	std::cout << std::endl;

	delete tmp;
	delete tmp2;
	delete src;
	*/

	return 0;
}
