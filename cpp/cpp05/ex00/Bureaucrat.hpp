/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:51:57 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/11 16:41:37 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>
#include <iostream>

#define RESET "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CYAN "\e[0;36m"
#define WHITE "\e[0;37m"

#define COLOR(text, color) color << text << RESET

class Bureaucrat {

	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat&	operator=(const Bureaucrat& rhs);
		~Bureaucrat(void);

		const std::string	getName(void) const;
		int					getGrade(void) const;

		void				incGrade(void);
		void				decGrade(void);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char*	what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};

	private:
		const std::string	_name;
		int					_grade;

};

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& rhs);

#endif
