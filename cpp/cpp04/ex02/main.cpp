/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:58:29 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/08 11:34:45 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	//Test to check if we can instantiate the AAnimal class without using a derived class
	// const AAnimal test;

	const AAnimal* j = new Dog();
	const AAnimal* k = new Cat();

	std::cout << std::endl;

	delete j;//should not create a leak
	delete k;

	/*
	int	N = 4;
	AAnimal*	array[N];

	for (int i = 0; i < N; i++)
	{
		if (i == N / 2)
			std::cout << std::endl;
		if (i < N / 2)
			array[i] = new Dog();
		else
			array[i] = new Cat();
	}

	std::cout << std::endl << std::endl;

	for (int i = 0; i < N; i++)
	{
		if (i == N / 2)
			std::cout << std::endl;
		array[i]->makeSound();
	}

	std::cout << std::endl << std::endl;

	for (int i = 0; i < N; i++)
	{
		if (i == N / 2)
			std::cout << std::endl;
		delete array[i];
	}
	*/

	/*
	//Test to see if it's a deep copy or shallow copy
	Cat basic;
	basic.setIdea("oui", 1);
	std::cout << std::endl;

	{
		Cat tmp = basic;

		//The copy was successful, we have the content of the source (basic)
		std::cout << std::endl << "tmp.getIdea -> " << tmp.getIdea(1) << std::endl << std::endl;

		//Set of destructors call for tmp after this line, since we will be out of the scope.
	}

	//We can still manipulate the content of the brain of basic
	std::cout << std::endl << "basic.getIdea -> " << basic.getIdea(1) << std::endl << std::endl;

	//Set of destructors call for basic after this line, since we will be out of the main.
	*/

	/*
	//Another test to see if it's a deep copy or shallow copy but I prefer the one above
	Cat *catPTR = new Cat();
	catPTR->setIdea("myCatIdea", 0);
	std::cout << "catPTR idea: " << catPTR->getIdea(0) << std::endl;

	Cat *catCOPY = new Cat(*catPTR);
	std::cout << "catCOPY idea: " << catCOPY->getIdea(0) << std::endl;

	std::cout << std::endl;

	delete catPTR;
	delete catCOPY;
	*/

	return 0;
}
