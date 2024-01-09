/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:33:53 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:26:13 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("default") {

	if (SHOWMSG)
		std::cout << COLOR("PresidentialPardonForm", MAGENTAUNDER) << COLOR(" Default constructor called", GREEN) << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src), _target(src._target) {

	if (SHOWMSG)
		std::cout << COLOR("PresidentialPardonForm", MAGENTAUNDER) << COLOR(" Copy constructor called", GREEN) << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {

	if (this != &rhs)
		this->_target = rhs._target;

	if (SHOWMSG)
		std::cout << COLOR("PresidentialPardonForm", MAGENTAUNDER) << COLOR(" Assignation operator called", GREEN) << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {

	if (SHOWMSG)
		std::cout << COLOR("PresidentialPardonForm", MAGENTAUNDER) << COLOR(" Destructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                           PARAMETRIC CONSTRUCTOR                           */
/* ************************************************************************** */

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {

	if (SHOWMSG)
		std::cout << COLOR("PresidentialPardonForm", MAGENTAUNDER) << COLOR(" Parametric constructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                        OVERLOADED HERITED FUNCTIONS                        */
/* ************************************************************************** */

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {

	if (this->getSigned() == false)
		throw AForm::NotSignedException();

	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	else
		std::cout << "🎉 Yay, " << COLOR(this->_target, GREENUNDER) << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
