/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 08:49:53 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:19:49 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

//In private since we have a constructor to set all values
Form::Form(void) : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExec(150) {

	if (SHOWMSG)
		std::cout << COLOR("Form ", GREEN) << COLOR(this->_name, MAGENTA) << COLOR(" Default constructor called", GREEN) << std::endl;
}

Form::Form(const Form& src) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec) {

	if (SHOWMSG)
		std::cout << COLOR("Form ", GREEN) << COLOR(this->_name, MAGENTA) << COLOR(" Copy constructor called", GREEN) << std::endl;
}

//In private since _name, _gradeToSign and _gradeToExec are const
Form&	Form::operator=(const Form& rhs) {

	if (this != &rhs)
		this->_signed = rhs._signed;

	if (SHOWMSG)
		std::cout << COLOR("Form ", GREEN) << COLOR(this->_name, MAGENTA) << COLOR(" Assignation operator called", GREEN) << std::endl;

	return (*this);
}

Form::~Form(void) {

	if (SHOWMSG)
		std::cout << COLOR("Form ", RED) << COLOR(this->_name, MAGENTA) << COLOR(" destructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                          PARAMETRIC CONSTRUCTOR                           */
/* ************************************************************************** */

Form::Form(const std::string name, int gradeSign, int gradeExec) : _name(name), _signed(false), _gradeToSign(gradeSign), _gradeToExec(gradeExec) {

	checkValidValue(gradeSign);
	checkValidValue(gradeExec);

	if (SHOWMSG)
		std::cout << COLOR("Form ", GREEN) << COLOR(this->_name, MAGENTA) << COLOR(" Parametric constructor called", GREEN) << std::endl;
}

/* ************************************************************************** */
/*                                     GETTERS                                */
/* ************************************************************************** */

const std::string	Form::getName(void) const {

	return (this->_name);
}

bool	Form::getSigned(void) const {

	return (this->_signed);
}

int	Form::getGradeSign(void) const {

	return (this->_gradeToSign);
}

int	Form::getGradeExec(void) const {

	return (this->_gradeToExec);
}



void	Form::beSigned(Bureaucrat& bureaucrat) {

	if (bureaucrat.getGrade() <= this->getGradeSign()) {
		if (this->getSigned() == true)
			throw Form::FormAlreadySignedException();
		this->_signed = true;
	}
	else
		throw Form::GradeTooLowException();
}

void	Form::checkValidValue(int grade) {

	if (grade < 1) {
		std::cout << COLOR("Form: ", MAGENTA);
		throw GradeTooHighException();
	}
	else if (grade > 150) {
		std::cout << COLOR("Form: ", MAGENTA);
		throw GradeTooLowException();
	}
}

/* ************************************************************************** */
/*                             EXCEPTION CLASSES                              */
/* ************************************************************************** */

const char*	Form::GradeTooHighException::what() const throw() {

	return (RED "Grade is too high !" RESET);
}

const char* Form::GradeTooLowException::what() const throw() {

	return (RED "Grade is too low !" RESET);
}

const char* Form::FormAlreadySignedException::what() const throw() {

	return (RED "Form is already signed !" RESET);
}

/* ************************************************************************** */
/*                               EXTRA FUNCTION                               */
/* ************************************************************************** */

std::ostream&	operator<<(std::ostream& o, const Form& f) {

	if (f.getSigned() == true)
		o << COLOR(f.getName(), MAGENTA) << COLOR(" Form is ", CYAN) << COLOR("signed", GREEN) <<
			COLOR(", his required grade to sign it is ", CYAN) << COLOR(f.getGradeSign(), GREEN) << \
			COLOR(" and his required grade to execute it is ", CYAN) << COLOR(f.getGradeExec(), GREEN) << \
			COLOR(".", CYAN) << RESET;
	else
		o << COLOR(f.getName(), MAGENTA) << COLOR(" Form is ", CYAN) << COLOR("not signed", GREEN) <<
			COLOR(", his required grade to sign it is ", CYAN) << COLOR(f.getGradeSign(), GREEN) << \
			COLOR(" and his required grade to execute it is ", CYAN) << COLOR(f.getGradeExec(), GREEN) << \
			COLOR(".", CYAN) << RESET;

	return (o);
}
