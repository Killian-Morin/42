/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:01:43 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/06 17:26:03 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource *src = new MateriaSource();
	std::cout << std::endl;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << std::endl;

	ICharacter *me = new Character("me");
	std::cout << std::endl;

	// AMateria *tmp;
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// tmp->use(*me);

	// ICharacter *bob = new Character("bob");

	// me->use(0, *bob);
	// me->use(1, *bob);

	std::cout << std::endl;
	// delete bob;
	delete me;
	delete src;

	// test for the use() of Cure and Ice classes
	/*ICharacter*	joe = new Character("joe");
	std::cout << std::endl;
	Cure*	cure = new Cure();
	Ice*	ice = new Ice();
	std::cout << std::endl;
	cure->use(*joe);
	ice->use(*joe);

	std::cout << std::endl;
	delete joe;
	delete cure;
	delete ice;*/

	return 0;
}
