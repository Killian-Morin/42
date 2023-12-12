/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:40:14 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/12 16:26:52 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

Intern::Intern(void)
{
	if (SHOWMSG)
		std::cout << COLOR("Intern ", BLUEUNDER) << COLOR(" Default constructor called", GREEN) << std::endl;
}

//In private since has nothing to copy
Intern::Intern(const Intern& src)
{
	(void)src;
	if (SHOWMSG)
		std::cout << COLOR("Intern ", BLUEUNDER) << COLOR(" Copy constructor called", GREEN) << std::endl;
}

//In private since has nothing to copy
Intern&	Intern::operator=(const Intern& rhs)
{
	(void)rhs;
	if (SHOWMSG)
		std::cout << COLOR("Intern ", BLUEUNDER) << COLOR(" Assignation operator called", GREEN) << std::endl;
	return (*this);
}

Intern::~Intern(void)
{
	if (SHOWMSG)
		std::cout << COLOR("Intern ", BLUEUNDER) << COLOR(" destructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                              MEMBERS FUNCTIONS                             */
/* ************************************************************************** */

AForm*	Intern::makeForm(std::string formName, std::string target)
{
	std::string	forms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	AForm*	(Intern::*methods[])(const std::string) = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i] ==	formName)
		{
			std::cout << COLOR("Intern", BLUEUNDER) << " creates " << COLOR(formName, MAGENTAUNDER) << std::endl;
			return (this->*methods[i])(target);
		}
	}

	std::cout << COLOR("Error: Unknown form name.", RED) << "You can choose between: " << \
		COLOR("ShrubberyCreationForm", MAGENTAUNDER) << ", " << \
		COLOR("RobotomyRequestForm", MAGENTAUNDER) << ", " << \
		COLOR("PresidentialPardonForm", MAGENTAUNDER) << std::endl;
	return (NULL);
}

AForm*	Intern::makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}
