/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:38:35 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/22 14:18:30 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>

#include "Weapon.hpp"

//No default constructor even though it doesn't have a reference attribut
//since I didn't create a setter for the name attribut
class HumanB
{
	public:
		HumanB(std::string name);
		~HumanB();

		void	attack(void);

		void	setWeapon(Weapon& weapon);

	private:
		std::string	_name;
		Weapon*		_weapon;
};

#endif
