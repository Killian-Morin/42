/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:38:35 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/21 11:53:38 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>

#include "Weapon.hpp"

#define RED "\033[31m"
#define WHITE "\033[37m"

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
