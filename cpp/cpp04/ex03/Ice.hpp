/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:26:57 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/07 10:13:19 by kmorin           ###   ########.fr       */
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
		Ice(void);
		Ice(Ice const& src);
		Ice&	operator=(Ice const& rhs);
		virtual ~Ice(void);

		virtual AMateria*	clone() const;
		virtual void		use(ICharacter& target);

};

#endif
