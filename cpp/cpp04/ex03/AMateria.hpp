/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:01:36 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/08 11:43:23 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <string>

#include "ICharacter.hpp"
#include "Color.hpp"

class ICharacter;

class AMateria {

	public:
		AMateria(void);
		AMateria(AMateria const &src);
		AMateria(std::string const & type);
		AMateria&	operator=(const AMateria &rhs);
		virtual ~AMateria(void);

		std::string const &	getType() const;

		virtual AMateria*	clone() const = 0;//not implemented since virtual pure function
		virtual void		use(ICharacter& target);

	protected:
		std::string _type;

};

#endif
