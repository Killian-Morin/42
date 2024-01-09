/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:40:17 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:50:43 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {

	private:
		Intern(const Intern& src);
		Intern&	operator=(const Intern& rhs);

		AForm*	makeShrubberyCreationForm(std::string target);
		AForm*	makeRobotomyRequestForm(std::string target);
		AForm*	makePresidentialPardonForm(std::string target);

	public:
		//Canonical class functions
		Intern(void);
		~Intern(void);

		//Member Functions
		AForm*	makeForm(std::string formName, std::string target);
};

#endif //INTERN_HPP
