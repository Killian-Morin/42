/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:33:42 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:27:59 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>

#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {

	private:
		std::string	_target;

	public:
		//Canonical class functions
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm& src);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& rhs);
		~ShrubberyCreationForm(void);

		//Parametric constructor
		ShrubberyCreationForm(const std::string target);

		//Overloaded herited functions
		void	execute(Bureaucrat const & executor) const;
};

#endif //SHRUBBERYCREATIONFORM_HPP
