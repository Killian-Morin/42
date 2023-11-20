/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:38:35 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/20 17:02:21 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>

#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name, Weapon weapon);
		~HumanB();
		
		void	attack(void);
		
		void	setWeapon(Weapon weapon);

		HumanB();
	
	private:
		std::string	_name;
		std::string	_weapon;
};

#endif
