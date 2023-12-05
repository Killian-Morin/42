/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:38:47 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/05 15:33:58 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

#define RESET "\e[0m"
#define RED "\033[31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CYAN "\e[0;36m"
#define WHITE "\033[37m"

#define COLOR(text, color) color << text << RESET

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon(void);

		const std::string&	getType(void);
		void				setType(std::string newType);

	private:
		std::string	_type;
};

#endif
