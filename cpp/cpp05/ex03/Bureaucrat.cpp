/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:33:57 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:50:11 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

//In private since we have a constructor to set all values
Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150) {
	if (SHOWMSG)
		std::cout << COLOR("Bureaucrat ", GREEN) << COLOR(this->_name, BLUE) << COLOR(" Default constructor called", GREEN) << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade) {

	if (SHOWMSG)
		std::cout << COLOR("Bureaucrat ", GREEN) << COLOR(this->_name, BLUE) << COLOR(" Copy constructor called", GREEN) << std::endl;
}

//In private since _name is const
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs) {

	if (this != &rhs)
		this->_grade = rhs._grade;

	if (SHOWMSG)
		std::cout << COLOR("Bureaucrat ", GREEN) << COLOR(this->_name, BLUE) << COLOR(" Assignation operator called", GREEN) << std::endl;

	return (*this);
}

Bureaucrat::~Bureaucrat(void) {

	if (SHOWMSG)
		std::cout << COLOR("Bureaucrat ", RED) << COLOR(this->_name, BLUE) << COLOR(" destructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                           PARAMETRIC CONSTRUCTOR                           */
/* ************************************************************************** */

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {

	checkValidValue(grade);

	if (SHOWMSG)
		std::cout << COLOR("Bureaucrat ", GREEN) << COLOR(this->_name, BLUE) << COLOR(" Parametric constructor called", GREEN) << std::endl;
}

/* ************************************************************************** */
/*                                   GETTERS                                  */
/* ************************************************************************** */

const std::string	Bureaucrat::getName(void) const {

	return (this->_name);
}

int	Bureaucrat::getGrade(void) const {

	return (this->_grade);
}

/* ************************************************************************** */
/*                               MEMBER FUNCTIONS                             */
/* ************************************************************************** */

/*
	Increment is an upgrade of the grade but a downgrade of the number
*/
void	Bureaucrat::incGrade(void) {

	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;

	std::cout << COLOR("Bureaucrat ", YELLOW) << COLOR(this->getName(), BLUE) << \
		COLOR(" incremented his grade from ", YELLOW) << COLOR(this->getGrade() + 1, GREEN) << \
		COLOR(" to ", YELLOW) << COLOR(this->getGrade(), GREEN) << RESET << std::endl;
}

/*
	Decrement is a downgrade of the grade but an upgrade of the number
*/
void	Bureaucrat::decGrade(void) {

	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;

	std::cout << COLOR("Bureaucrat ", YELLOW) << COLOR(this->getName(), BLUE) << \
		COLOR(" decremented his grade from ", YELLOW) << COLOR(this->getGrade() - 1, GREEN) << \
		COLOR(" to ", YELLOW) << COLOR(this->getGrade(), GREEN) << RESET << std::endl;
}

void	Bureaucrat::checkValidValue(int grade) {

	if (grade < 1) {
		std::cout << COLOR("Bureaucrat: ", BLUE);
		throw GradeTooHighException();
	}
	else if (grade > 150) {
		std::cout << COLOR("Bureaucrat: ", BLUE);
		throw GradeTooLowException();
	}
}

void	Bureaucrat::signForm(AForm& AForm) {

	try {
		AForm.beSigned(*this);
		std::cout << COLOR(this->getName(), BLUE) << " signed " << COLOR(AForm.getName(), MAGENTA) << "." << std::endl;
	}
	catch (std::exception& e) {
		std::cout << COLOR(this->getName(), BLUE) << " couldn't sign " << COLOR(AForm.getName(), MAGENTA) << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form) {

	if (form.getSigned() == true && this->getGrade() <= form.getGradeExec())
		std::cout << COLOR(this->getName(), BLUE) << " executed " << COLOR(form.getName(), MAGENTA) << "." << std::endl;

	form.execute(*this);
}

/* ************************************************************************** */
/*                             EXCEPTION CLASSES                              */
/* ************************************************************************** */

const char*	Bureaucrat::GradeTooHighException::what() const throw() {

	return (RED "Grade is too high !" RESET);
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {

	return (RED "Grade is too low !" RESET);
}

/* ************************************************************************** */
/*                               EXTRA FUNCTION                               */
/* ************************************************************************** */

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& b) {

	o << COLOR(b.getName(), BLUE) << COLOR(", bureaucrat grade ", CYAN) << \
		COLOR(b.getGrade(), GREEN) << COLOR(".", CYAN) << RESET;

	return (o);
}
