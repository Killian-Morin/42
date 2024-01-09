/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:33:51 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:27:47 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("default") {

	if (SHOWMSG)
		std::cout << COLOR("RobotomyRequestForm", MAGENTAUNDER) << COLOR(" Default constructor called", GREEN) << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src), _target(src._target) {

	if (SHOWMSG)
		std::cout << COLOR("RobotomyRequestForm", MAGENTAUNDER) << COLOR(" Copy constructor called", GREEN) << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {

	if (this != &rhs)
		this->_target = rhs._target;

	if (SHOWMSG)
		std::cout << COLOR("RobotomyRequestForm", MAGENTAUNDER) << COLOR(" Assignation operator called", GREEN) << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {

	if (SHOWMSG)
		std::cout << COLOR("RobotomyRequestForm", MAGENTAUNDER) << COLOR(" Destructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                           PARAMETRIC CONSTRUCTOR                           */
/* ************************************************************************** */

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {

	if (SHOWMSG)
		std::cout << COLOR("RobotomyRequestForm", MAGENTAUNDER) << COLOR(" Parametric constructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                        OVERLOADED HERITED FUNCTIONS                        */
/* ************************************************************************** */

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {

	if (this->getSigned() == false)
		throw AForm::NotSignedException();

	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << "Drilling noises: Bbbbbzzzzzzzzzzz" << std::endl;
		srand(time(NULL));//initialize a random seed for rand based on each execution time
		if (rand() % 2 == 0)
			std::cout << "🎉 Yay, " << COLOR(this->_target, GREENUNDER) << " has been successfully robotomized !" << std::endl;
		else
			std::cout << "😞 " << COLOR(this->_target, GREENUNDER) << " has failed the robotomy. " << std::endl;
	}
}
