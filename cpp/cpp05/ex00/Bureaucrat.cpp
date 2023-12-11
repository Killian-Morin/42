/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:52:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/11 17:00:41 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ************************************************************************** */
/*                  CANONIC METHODS and SPECIAL CONSTRUCTORS                  */
/* ************************************************************************** */

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150)
{
	std::cout << COLOR("Bureaucrat " + this->_name + " Default constructor called", GREEN) << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << COLOR("Bureaucrat " + this->_name + " Parametric constructor called", GREEN) << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade)
{
	std::cout << COLOR("Bureaucrat " + this->_name + " Copy constructor called", GREEN) << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
	{
		this->_grade = rhs._grade;
	}
	std::cout << COLOR("Bureaucrat " + this->_name + " Assignation operator called", GREEN) << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << COLOR("Bureaucrat " + this->_name + " destroyed", RED) << std::endl;
}

/* ************************************************************************** */
/*                              MEMBERS FUNCTIONS                             */
/* ************************************************************************** */

const std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

/*
	Increment is an upgrade of the grade but a downgrade of the number
*/
void	Bureaucrat::incGrade(void)
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
	std::cout << YELLOW << "Bureaucrat " + this->getName();
	std::cout << " incremented his grade from " << this->getGrade() + 1 << " to " << this->getGrade() << RESET << std::endl;
}

/*
	Decrement is a downgrade of the grade but an upgrade of the number
*/
void	Bureaucrat::decGrade(void)
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
	std::cout << MAGENTA << "Bureaucrat " + this->getName();
	std::cout << " decremented his grade from " << this->getGrade() - 1 << " to " << this->getGrade() << RESET <<  std::endl;
}

/* ************************************************************************** */
/*                      NESTED CLASSES MEMBERS FUNCTIONS                      */
/* ************************************************************************** */

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return (RED "Grade too high" RESET);
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return (RED "Grade too low" RESET);
}

/* ************************************************************************** */
/*                                   OTHERS                                   */
/* ************************************************************************** */

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& src)
{
	o << CYAN << src.getName() << ", bureaucrat grade " << src.getGrade() << RESET;
	return (o);
}
