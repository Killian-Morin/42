/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:38:32 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/05 17:02:42 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& src);
		MateriaSource&	operator=(const MateriaSource& rhs);
		~MateriaSource(void);

		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const& type);

};

#endif
