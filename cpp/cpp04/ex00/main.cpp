/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:58:29 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 12:47:31 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {

	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << std::endl;

	std::cout << "j is a " << j->getType() << " " << std::endl;
	std::cout << "i is a " << i->getType() << " " << std::endl;

	std::cout << std::endl;

	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;

	/*
	const WrongAnimal* k = new WrongAnimal();
	const WrongAnimal* l = new WrongCat();

	std::cout << std::endl;

	std::cout << "k is a " << k->getType() << " " << std::endl;
	std::cout << "l is a " << l->getType() << " " << std::endl;

	std::cout << std::endl;

	k->makeSound();
	l->makeSound();

	std::cout << std::endl;

	delete k;
	delete l;
	*/

	return 0;
}
