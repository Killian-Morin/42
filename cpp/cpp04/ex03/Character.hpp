/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:38:22 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:34:45 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>

#include "ICharacter.hpp"

class Character : public ICharacter {

	private:
		std::string	_name;
		int			_idxInventory;
		AMateria*	_inventory[4];
		int			_idxUnequiped;
		AMateria*	_unequipedInventory[4];
		void		handleUnequipedInventory(int idx);

	public:
		//Canonical class functions
		Character(void);
		Character(Character const& src);
		Character&	operator=(Character const& rhs);
		virtual ~Character(void);

		//Parametric constructor
		Character(std::string const& name);

		//Overloaded herited functions
		virtual std::string const&	getName(void) const;
		virtual void				equip(AMateria* m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter& target);
};

#endif //CHARACTER_HPP
