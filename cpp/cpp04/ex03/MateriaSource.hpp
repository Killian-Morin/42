/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:38:32 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:34:16 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class AMateria;

class MateriaSource : public IMateriaSource {

	private:
		int			_idxMaterias;
		AMateria*	_materias[4];

	public:
		//Canonical class functions
		MateriaSource(void);
		MateriaSource(const MateriaSource& src);
		MateriaSource&	operator=(const MateriaSource& rhs);
		virtual ~MateriaSource(void);

		//Overloaded herited functions
		virtual void		learnMateria(AMateria*);
		virtual AMateria*	createMateria(std::string const& type);

		//Extra Function
		virtual void		displayMateriasLearned(void) const;//uncomment in IMateriaSource.hpp to be able to use it
};

#endif //MATERIASOURCE_HPP
