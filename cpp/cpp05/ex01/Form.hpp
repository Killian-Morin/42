/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 08:49:55 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:38:26 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;

		Form(void);
		Form&	operator=(const Form& rhs);

		void				checkValidValue(int grade);

	public:
		//Canonical class functions
		Form(const Form& src);
		~Form(void);

		//Parametric Constructor
		Form(const std::string name, int gradeSign, int gradeExec);

		//Getters
		const std::string	getName(void) const;
		bool				getSigned(void) const;
		int					getGradeSign(void) const;
		int					getGradeExec(void) const;

		//Member Functions
		void				beSigned(Bureaucrat& bureaucrat);

		//Exceptions classes
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class FormAlreadySignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

//Operator overload to print Form class info
std::ostream&	operator<<(std::ostream& o, const Form& f);

#endif //FORM_HPP
