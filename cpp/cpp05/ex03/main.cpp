/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:33:54 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/12 16:32:07 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

/* ************************************************************************** */

int	main(void)
{
	std::cout << std::endl;

	AForm*	ptr;

	try {
		Intern	intern;
		Bureaucrat	tester("tester", 1);

		ptr = intern.makeForm("ShrubberyCreationForm", "MOI");
		tester.signForm(*ptr);
		tester.executeForm(*ptr);
		delete	ptr;

		std::cout << std::endl;

		ptr = intern.makeForm("RobotomyRequestForm", "OUI");
		tester.signForm(*ptr);
		tester.executeForm(*ptr);
		delete	ptr;

		std::cout << std::endl;

		ptr = intern.makeForm("PresidentialPardonForm", "NON");
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
