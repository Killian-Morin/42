/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:01:36 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 14:57:36 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

#include "ICharacter.hpp"
#include "Color.hpp"

class ICharacter;

class AMateria {

	protected:
		std::string _type;

	public:
		//Canonical class functions
		AMateria(void);
		AMateria(AMateria const &src);
		AMateria&	operator=(const AMateria &rhs);
		virtual ~AMateria(void);

		//Parametric Constructor
		AMateria(std::string const & type);

		//Getter
		std::string const &	getType() const;

		//Member Functions
		virtual AMateria*	clone() const = 0;//not implemented since virtual pure function
		virtual void		use(ICharacter& target);
};

#endif //AMATERIA_HPP
