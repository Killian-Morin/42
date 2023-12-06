/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:26:10 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/06 11:30:27 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {

	public:
		Cure(void);
		Cure(const Cure &src);
		Cure&	operator=(const Cure &rhs);
		virtual ~Cure(void);

		virtual AMateria*	clone() const;
		virtual void		use(ICharacter& target);

};

#endif
