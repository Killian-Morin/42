/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:33:43 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:28:57 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("default") {

	if (SHOWMSG)
		std::cout << COLOR("ShrubberyCreationForm", MAGENTAUNDER) << COLOR(" Default constructor called", GREEN) << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src), _target(src._target) {

	if (SHOWMSG)
		std::cout << COLOR("ShrubberyCreationForm", MAGENTAUNDER) << COLOR(" Copy constructor called", GREEN) << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {

	if (this != &rhs)
		this->_target = rhs._target;

	if (SHOWMSG)
		std::cout << COLOR("ShrubberyCreationForm", MAGENTAUNDER) << COLOR(" Assignation operator called", GREEN) << std::endl;

	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {

	if (SHOWMSG)
		std::cout << COLOR("ShrubberyCreationForm", MAGENTAUNDER) << COLOR(" Destructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                           PARAMETRIC CONSTRUCTOR                           */
/* ************************************************************************** */

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {

	if (SHOWMSG)
		std::cout << COLOR("ShrubberyCreationForm", MAGENTAUNDER) << COLOR(" Parametric constructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                        OVERLOADED HERITED FUNCTIONS                        */
/* ************************************************************************** */

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {

	if (this->getSigned() == false)
		throw AForm::NotSignedException();

	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	else
	{
		std::ofstream	tree;
		tree.open(this->_target + "_shrubbery", std::ofstream::out);
		if (!tree.good()) {
			std::cout << COLOR("Sorry ", RED) << COLOR(this->_target + "_shrubbery", GREENUNDER) << \
				COLOR("couldn't be created.", RED) << std::endl;
			return ;
		}

		std::string	line;
		tree << ".     .  .      +     .      .          ." << std::endl;
		tree << "     .       .      .     #       .           ." << std::endl;
		tree << "        .      .         ###            .      .      ." << std::endl;
		tree << "      .      .   \"#:. .:##\"##:. .:#\"  .      ." << std::endl;
		tree << "          .      . \"####\"###\"####\"  ." << std::endl;
		tree << "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       ." << std::endl;
		tree << "  .             \"#########\"#########\"        .        ." << std::endl;
		tree << "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       ." << std::endl;
		tree << "     .     .  \"#######\"\"##\"##\"\"#######\"                  ." << std::endl;
		tree << "                .\"##\"#####\"#####\"##\"           .      ." << std::endl;
		tree << "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     ." << std::endl;
		tree << "      .     \"#######\"##\"#####\"##\"#######\"      .     ." << std::endl;
		tree << "    .    .     \"#####\"\"#######\"\"#####\"    .      ." << std::endl;
		tree << "            .     \"      000      \"    .     ." << std::endl;
		tree << "       .         .   .   000     .        .       ." << std::endl;
		tree << ".. .. ..................O000O........................ ......" << std::endl;

		tree.close();
		std::cout << "🎉 Yay, we successfully created a " << COLOR(this->_target + "_shrubbery", GREENUNDER) << \
			" where we copied an awesome tree." << std::endl;
	}
}
