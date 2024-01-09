/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:33:56 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:38:50 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>
#include <iostream>

#include "AForm.hpp"

#ifndef SHOWMSG
# define SHOWMSG 0
#endif //SHOWMSG

#define RESET "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CYAN "\e[0;36m"
#define WHITE "\e[0;37m"

#define GREENUNDER "\e[4;32m"
#define MAGENTAUNDER "\e[4;35m"

#define COLOR(text, color) color << text << RESET

class AForm;

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

		void				signForm(AForm& AForm);

		void				executeForm(AForm const & form);

		//Nested Classes for my exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

//Operator overload to print Bureaucrat class info
std::ostream&	operator<<(std::ostream& o, const Bureaucrat& b);

#endif
