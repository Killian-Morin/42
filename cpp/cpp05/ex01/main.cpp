/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:51:26 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/12 11:22:35 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	creationformOK(void)
{
	try {
		Form	form("test", 1, 1);
		std::cout << form << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	creationformSignNO(void)
{
	try {
		// Form	form("test", 0, 1);
		Form	form("test", 151, 1);
		std::cout << form << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	creationformExecNO(void)
{
	try {
		// Form	form("test", 1, 151);
		Form	form("test", 1, 0);
		std::cout << form << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	signOK(void)
{
	try {
		Bureaucrat	bob("Bob", 150);
		Form		form("1080p", 150, 1);
		std::cout << bob << std::endl;
		std::cout << form << std::endl;

		bob.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	signNO(void)
{
	try {
		Bureaucrat	bob("Bob", 150);
		Form		form("1080p", 149, 1);
		std::cout << bob << std::endl;
		std::cout << form << std::endl;

		bob.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int	main(void)
{
	std::cout << std::endl;

	creationformOK();
	creationformSignNO();
	creationformExecNO();

	signOK();
	signNO();

	return (0);
}
