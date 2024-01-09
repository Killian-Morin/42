/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:33:45 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:27:01 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm {

	private:
		std::string	_target;

	public:
		//Canonical class functions
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm& src);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& rhs);
		~RobotomyRequestForm(void);

		//Parametric constructor
		RobotomyRequestForm(const std::string target);

		//Overloaded herited functions
		void	execute(Bureaucrat const & executor) const;
};

#endif //ROBOTOMYREQUESTFORM_HPP
