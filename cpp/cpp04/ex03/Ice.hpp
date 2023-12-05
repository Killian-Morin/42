/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:26:57 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/05 16:33:48 by kmorin           ###   ########.fr       */
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
		virtual ~Ice();

		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif
