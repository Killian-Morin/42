/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:51:26 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:07:46 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ************************************************************************** */

void	creationformOK(void) {

	try {
		std::cout << "Test for the creation of a form with valid grades: " << std::endl;
		Form	form("test", 1, 1);
		std::cout << form << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}

/* ************************************************************************** */

void	creationformSignNO(void) {

	try {
		std::cout << "Test for the creation of a form with invalid signing grades: " << std::endl;
		// Form	form("test", 0, 1);
		Form	form("test", 151, 1);
		std::cout << form << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}

/* ************************************************************************** */

void	creationformExecNO(void) {

	try {
		std::cout << "Test for the creation of a form with invalid executing grades: " << std::endl;
		// Form	form("test", 1, 151);
		Form	form("test", 1, 0);
		std::cout << form << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}

/* ************************************************************************** */

void	signOK(void) {

	try {
		std::cout << "Test for signing a form with a grade meeting the requirements: " << std::endl;
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

/* ************************************************************************** */

void	signNO(void) {

	try {
		std::cout << "Test for signing a form with a signing grade not meeting the requirements: " << std::endl;
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

/* ************************************************************************** */

void	signDouble(void) {

	try {
		std::cout << "Test for signing an already signed form: " << std::endl;
		Bureaucrat	bob("Bob", 1);
		Form		form("1080p", 140, 1);
		std::cout << bob << std::endl;
		std::cout << form << std::endl;

		bob.signForm(form);
		std::cout << form << std::endl;

		bob.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}

/* ************************************************************************** */
/* ************************************************************************** */

int	main(void) {

	std::cout << std::endl;

	creationformOK();
	creationformSignNO();
	creationformExecNO();

	signOK();
	signNO();
	signDouble();

	return (0);
}
