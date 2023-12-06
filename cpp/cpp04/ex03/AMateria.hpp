/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:01:36 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/06 17:13:49 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

#include "ICharacter.hpp"

#define RESET "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CYAN "\e[0;36m"
#define WHITE "\e[0;37m"

#define CYANBACKG "\e[46m"

#define MAGENTAULINE "\e[4;35m"

#define COLOR(text, color) color << text << RESET

class ICharacter;

class AMateria {

	public:
		AMateria(void);
		AMateria(const AMateria &src);
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
