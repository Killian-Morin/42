/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:33:54 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:51:37 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

/* ************************************************************************** */

int	main(void) {

	std::cout << std::endl;

	AForm*	ptr;

	try {
		Intern	intern;
		Bureaucrat	tester("tester", 1);
		std::cout << "The Bureaucrat that will accompany us throughout this main(): ";
		std::cout << tester << std::endl << std::endl;

		std::cout << "Test to see if a Bureaucrat can sign and execute a ShrubberyCreationForm created by an Intern via makeForm:" \
			<< std::endl;
		ptr = intern.makeForm("shrubbery creation", "MOI");
		tester.signForm(*ptr);
		tester.executeForm(*ptr);
		delete	ptr;

		std::cout << std::endl;

		std::cout << "Test to see if a Bureaucrat can sign and execute a RobotomyRequestForm created by an Intern via makeForm:" \
			<< std::endl;
		ptr = intern.makeForm("robotomy request", "OUI");
		tester.signForm(*ptr);
		tester.executeForm(*ptr);
		delete	ptr;

		std::cout << std::endl;

		std::cout << "Test to see if a Bureaucrat can sign and execute a PresidentialPardonForm created by an Intern via makeForm:" \
			<< std::endl;
		ptr = intern.makeForm("presidential pardon", "NON");
		tester.signForm(*ptr);
		tester.executeForm(*ptr);
		delete	ptr;

		std::cout << std::endl;

		std::cout << "Test to see if an Intern can create a Form with a wrong Form name via makeForm:" \
			<< std::endl;
		ptr = intern.makeForm("pardon", "NON");
		tester.signForm(*ptr);
		tester.executeForm(*ptr);
		delete	ptr;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	return (0);
}
