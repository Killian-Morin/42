/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:51:57 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/12 10:41:37 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>
#include <iostream>

#include "Form.hpp"

#ifndef SHOWMSG
# define SHOWMSG 0
#endif

#define RESET "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CYAN "\e[0;36m"
#define WHITE "\e[0;37m"

#define COLOR(text, color) color << text << RESET

class Form;

class Bureaucrat {

	private:
		const std::string	_name;
		int					_grade;

		Bureaucrat(void);
		Bureaucrat&	operator=(const Bureaucrat& rhs);

		void				checkValidValue(int grade);

	public:
		//Canonical class functions
		Bureaucrat(const Bureaucrat& src);
		~Bureaucrat(void);
		//Parametric constructor
		Bureaucrat(const std::string name, int grade);

		//Member Functions
		const std::string	getName(void) const;
		int					getGrade(void) const;

		void				incGrade(void);
		void				decGrade(void);

		void				signForm(Form& form);

		//Nested Classes for my exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

};

//Operator overload to print Bureaucrat class info
std::ostream&	operator<<(std::ostream& o, const Bureaucrat& b);

#endif
