/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:38:35 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 09:31:33 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>

#include "Weapon.hpp"

class HumanB {

	private:
		std::string	_name;
		Weapon*		_weapon;

	public:
		//Parametric Constructor/Destructor
		HumanB(std::string name);
		~HumanB(void);

		//Member Function
		void	attack(void);

		//Setter
		void	setWeapon(Weapon& weapon);
};

#endif //HUMANB_HPP
