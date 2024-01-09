/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:33:32 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:50:00 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;

		AForm(void);
		AForm&	operator=(const AForm& rhs);

		void				checkValidValue(int grade);

	public:
		//Canonical class functions
		AForm(const AForm& src);
		virtual ~AForm(void);

		//Parametric Constructor
		AForm(const std::string name, int gradeSign, int gradeExec);

		//Getters
		const std::string	getName(void) const;
		bool				getSigned(void) const;
		int					getGradeSign(void) const;
		int					getGradeExec(void) const;

		//Member Functions
		void				beSigned(Bureaucrat& bureaucrat);

		virtual void		execute(Bureaucrat const & executor) const = 0;

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

		class NotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

//Operator overload to print AForm class info
std::ostream&	operator<<(std::ostream& o, const AForm& f);

#endif //AFORM_HPP
