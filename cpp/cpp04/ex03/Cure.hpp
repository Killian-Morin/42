/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:26:10 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/07 10:06:13 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CURE_HPP
#define CURE_HPP

#include <string>

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class Cure : public AMateria {

	public:
		Cure(void);
		Cure(Cure const& src);
		Cure&	operator=(Cure const& rhs);
		virtual ~Cure(void);

		virtual AMateria*	clone() const;
		virtual void		use(ICharacter& target);

};

#endif