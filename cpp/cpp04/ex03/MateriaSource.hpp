/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:38:32 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/07 13:49:40 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class AMateria;

class MateriaSource : public IMateriaSource {

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& src);
		MateriaSource&	operator=(const MateriaSource& rhs);
		virtual ~MateriaSource(void);

		virtual void		learnMateria(AMateria*);
		virtual AMateria*	createMateria(std::string const& type);

		virtual void		displayMateriasLearned(void) const;//uncomment in IMateriaSource.hpp to be able to use it

	private:
		int			_idxMaterias;
		AMateria*	_materias[4];

};

#endif
