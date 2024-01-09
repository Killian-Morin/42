/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:33:52 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:51:59 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef	PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {

	private:
		std::string	_target;

	public:
		//Canonical class functions
		PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm& src);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& rhs);
		~PresidentialPardonForm(void);

		//Parametric constructor
		PresidentialPardonForm(const std::string target);

		//Overloaded herited functions
		void	execute(Bureaucrat const & executor) const;
};

#endif //PRESIDENTIALPARDONFORM_HPP
