/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:38:23 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 09:31:40 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>

#include "Weapon.hpp"

class HumanA {

	private:
		std::string	_name;
		Weapon&		_weapon;

	public:
		//Parametric Constructor/Destructor
		HumanA(std::string name, Weapon& weapon);
		~HumanA(void);

		//Member Function
		void	attack(void);
};

#endif //HUMANA_HPP
