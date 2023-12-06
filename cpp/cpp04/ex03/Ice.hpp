/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:26:57 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/06 11:30:30 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {

	public:
		Ice(void);
		Ice(const Ice & src);
		Ice&	operator=(Ice const & rhs);
		virtual ~Ice(void);

		virtual AMateria*	clone() const;
		virtual void		use(ICharacter& target);
};

#endif
