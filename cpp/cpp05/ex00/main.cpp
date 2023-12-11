/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:51:26 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/11 17:01:02 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	bob("Bob", 150);
	Bureaucrat	jim("Jim", 1);
	std::cout << std::endl;

	std::cout << COLOR("Inital values:", BLUE) << std::endl;
	std::cout << bob << std::endl;
	std::cout << jim << std::endl;
	std::cout << std::endl;

	try
	{
		bob.incGrade();
		bob.decGrade();
		jim.decGrade();
		jim.incGrade();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	/*catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}*/
	std::cout << std::endl;

	/*
	//Assignation operator test
	Bureaucrat	test;
	std::cout << test << std::endl;
	test = jim;
	std::cout << test << std::endl;
	*/

	return (0);
}
