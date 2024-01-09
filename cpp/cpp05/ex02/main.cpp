/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:33:54 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:18:37 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/* ************************************************************************** */

void	execForm(void) {

	try {
		std::cout << "Test grades to execute " << COLOR("PresidentialPardonForm", BLUE) << \
			" by having the sufficent grade and by signing first:" << std::endl;
		Bureaucrat	bureaucrat("a", 1);
		PresidentialPardonForm	tmp("MOI");

		std::cout << bureaucrat << std::endl;
		std::cout << tmp << std::endl;

		bureaucrat.signForm(tmp);
		std::cout << tmp << std::endl;

		tmp.execute(bureaucrat);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;

	try {
		std::cout << "Test grades to execute " << COLOR("RobotomyRequestForm", BLUE) << \
			" by having the sufficent grade and by signing first:" << std::endl;
		Bureaucrat	bureaucrat("a", 1);
		RobotomyRequestForm	tmp("MOI");

		std::cout << bureaucrat << std::endl;
		std::cout << tmp << std::endl;

		bureaucrat.signForm(tmp);
		std::cout << tmp << std::endl;

		tmp.execute(bureaucrat);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;

	try {
		std::cout << "Test grades to execute " << COLOR("ShrubberyCreationForm", BLUE) << \
			" by having the sufficent grade and by signing first:" << std::endl;
		Bureaucrat	bureaucrat("a", 1);
		ShrubberyCreationForm	tmp("MOI");

		std::cout << bureaucrat << std::endl;
		std::cout << tmp << std::endl;

		bureaucrat.signForm(tmp);
		std::cout << tmp << std::endl;

		tmp.execute(bureaucrat);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

/* ************************************************************************** */

void	execFormNotSigned(void) {

	try {
		std::cout << "Test to execute " << COLOR("PresidentialPardonForm", BLUE) << \
			" without signing first:" << std::endl;
		Bureaucrat	bureaucrat("a", 1);
		PresidentialPardonForm	tmp;

		std::cout << bureaucrat << std::endl;
		std::cout << tmp << std::endl;

		tmp.execute(bureaucrat);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;

	try {
		std::cout << "Test to execute " << COLOR("RobotomyRequestForm", BLUE) << \
			" without signing first:" << std::endl;
		Bureaucrat	bureaucrat("a", 1);
		RobotomyRequestForm	tmp;

		std::cout << bureaucrat << std::endl;
		std::cout << tmp << std::endl;

		tmp.execute(bureaucrat);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;

	try {
		std::cout << "Test to execute " << COLOR("ShrubberyCreationForm", BLUE) << \
			" without signing first:" << std::endl;
		Bureaucrat	bureaucrat("a", 1);
		ShrubberyCreationForm	tmp;

		std::cout << bureaucrat << std::endl;
		std::cout << tmp << std::endl;

		tmp.execute(bureaucrat);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

/* ************************************************************************** */

void	execFormNoPerm(void) {

	try {
		std::cout << "Test grades to sign and execute " << COLOR("PresidentialPardonForm", BLUE) << \
			" without the sufficient grade to sign or execute:" << std::endl;
		// Bureaucrat	bureaucrat("a", 6);//perm to sign but not execute
		Bureaucrat	bureaucrat("a", 26);//no perm to sign
		PresidentialPardonForm	tmp;

		std::cout << bureaucrat << std::endl;

		bureaucrat.signForm(tmp);
		std::cout << tmp << std::endl;

		tmp.execute(bureaucrat);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;

	try {
		std::cout << "Test grades to sign and execute " << COLOR("RobotomyRequestForm", BLUE) << \
			" without the sufficient grade to sign or execute:" << std::endl;
		// Bureaucrat	bureaucrat("a", 46);//perm to sign but not execute
		Bureaucrat	bureaucrat("a", 74);//no perm to sign
		RobotomyRequestForm	tmp;

		std::cout << bureaucrat << std::endl;

		bureaucrat.signForm(tmp);
		std::cout << tmp << std::endl;

		tmp.execute(bureaucrat);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;

	try {
		std::cout << "Test grades to sign and execute " << COLOR("ShrubberyCreationForm", BLUE) << \
			" without the sufficient grade to sign or execute:" << std::endl;
		// Bureaucrat	bureaucrat("a", 138);//perm to sign but not execute
		Bureaucrat	bureaucrat("a", 148);//no perm to sign
		ShrubberyCreationForm	tmp;

		std::cout << bureaucrat << std::endl;

		bureaucrat.signForm(tmp);
		std::cout << tmp << std::endl;

		tmp.execute(bureaucrat);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

/* ************************************************************************** */
/* ************************************************************************** */

int	main(void) {

	std::cout << std::endl;

	execForm();
	// execFormNotSigned();
	// execFormNoPerm();

	std::cout << std::endl;

	return (0);
}
