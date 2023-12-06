/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:38:32 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/06 15:27:48 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class AMateria;

class MateriaSource : public IMateriaSource {

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& src);
		MateriaSource&	operator=(const MateriaSource& rhs);
		~MateriaSource(void);

		virtual void		learnMateria(AMateria*);
		virtual AMateria*	createMateria(std::string const& type);

	private:
		AMateria*	materias[4];

};

#endif
