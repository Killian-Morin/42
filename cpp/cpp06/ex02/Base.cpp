/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:05:43 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 16:00:57 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

/* ************************************************************************** */
/*                               CLASS FUNCTION                               */
/* ************************************************************************** */

Base::~Base(void) {

	if (SHOWMSG)
		std::cout << COLOR("Base ", BLUE) << COLOR("Default constructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                             EXTERNAL FUNCTIONS                             */
/* ************************************************************************** */

Base*	generate(void) {

	srand(time(NULL));
	int	i = rand() % 3;

	if (i == 0)
		return (new A());
	else if (i == 1)
		return (new B());
	else
		return (new C());
}

void	identify(Base* p) {

	std::cout << COLOR("The class pointed to by a pointer is: ", BLUE);

	if (dynamic_cast<A *>(p))
		std::cout << COLOR("A", GREEN) << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << COLOR("B", YELLOW) << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << COLOR("C", MAGENTA) << std::endl;
}

void	identify(Base& p) {

	std::cout << COLOR("The class pointed to by a reference is: ", CYAN);

	try {
		(void)dynamic_cast<A &>(p);
		std::cout << COLOR("A", GREEN) << std::endl;
	}
	catch (const std::bad_cast& e) {
		// std::cerr << e.what() << std::endl;
	}

	try {
		(void)dynamic_cast<B &>(p);
		std::cout << COLOR("B", YELLOW) << std::endl;
	}
	catch (const std::bad_cast& e) {
		// std::cerr << e.what() << std::endl;
	}

	try {
		(void)dynamic_cast<C &>(p);
		std::cout << COLOR("C", MAGENTA) << std::endl;
	}
	catch (const std::bad_cast& e) {
		// std::cerr << e.what() << std::endl;
	}
}
