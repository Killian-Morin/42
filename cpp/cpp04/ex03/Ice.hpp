/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:26:57 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:33:05 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ICE_HPP
#define ICE_HPP

#include <string>

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class Ice : public AMateria {

	public:
		//Canonical class functions
		Ice(void);
		Ice(Ice const& src);
		Ice&	operator=(Ice const& rhs);
		virtual ~Ice(void);

		//Overloaded herited functions
		virtual AMateria*	clone() const;
		virtual void		use(ICharacter& target);

};

#endif //ICE_HPP
