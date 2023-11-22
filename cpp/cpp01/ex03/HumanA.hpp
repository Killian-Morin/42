/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:38:23 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/22 14:17:20 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>

#include "Weapon.hpp"

//No default constructor since we have a reference attribut
//this means that we need to init it in the constructor
class HumanA
{
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();

		void	attack(void);

	private:
		std::string	_name;
		Weapon&		_weapon;
};

#endif
