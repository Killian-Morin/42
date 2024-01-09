/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:51:26 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:02:58 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ************************************************************************** */

void	creationOK(void) {

	try {
		std::cout << "Test for creating a Bureaucrat with a valid grade: " << std::endl;
		Bureaucrat	ok("ok", 23);

		std::cout << ok << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}

/* ************************************************************************** */

void	creationNO(void) {

	try {
		std::cout << "Test for creating a Bureaucrat with an invalid grade: " << std::endl;
		Bureaucrat	no("no", 0);
		// Bureaucrat	no("no", 151);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}

/* ************************************************************************** */

void	incOK(void) {

	std::cout << "Test for incrementing the grade of a Bureaucrat: " << std::endl;
	Bureaucrat	bob("Bob", 150);

	std::cout << COLOR("Initial values: ", WHITE) << bob << std::endl;

	try {
		bob.incGrade();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << COLOR("After values: ", WHITE) << bob << std::endl;
	std::cout << std::endl;
}

/* ************************************************************************** */

void	decOK(void) {

	std::cout << "Test for decrementing the grade of a Bureaucrat: " << std::endl;
	Bureaucrat	bob("Bob", 1);

	std::cout << COLOR("Initial values: ", WHITE) << bob << std::endl;

	try {
		bob.decGrade();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << COLOR("After values: ", WHITE) << bob << std::endl;
	std::cout << std::endl;
}

/* ************************************************************************** */

void	incNO(void) {

	std::cout << "Test for incrementing the grade of a Bureaucrat already at the highest possible grade (1): " << std::endl;
	Bureaucrat	bob("Bob", 1);

	std::cout << COLOR("Initial values: ", WHITE) << bob << std::endl;

	try {
		bob.incGrade();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << COLOR("After values: ", WHITE) << bob << std::endl;
	std::cout << std::endl;
}

/* ************************************************************************** */

void	decNO(void) {

	std::cout << "Test for decrementing the grade of a Bureaucrat already at the lowest possible grade (150): " << std::endl;
	Bureaucrat	bob("Bob", 150);

	std::cout << COLOR("Initial values: ", WHITE) << bob << std::endl;

	try {
		bob.decGrade();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << COLOR("After values: ", WHITE) << bob << std::endl;
	std::cout << std::endl;
}

/* ************************************************************************** */
/* ************************************************************************** */

int	main(void) {

	std::cout << std::endl;

	creationOK();
	creationNO();

	incOK();
	decOK();
	incNO();
	decNO();

	return (0);
}
