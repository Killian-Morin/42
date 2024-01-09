/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:04:16 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 09:55:18 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iomanip>
#include <iostream>

#define RESET "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CYAN "\e[0;36m"
#define WHITE "\e[0;37m"

#define REDULINE "\e[4;31m"
#define GREENULINE "\e[4;32m"
#define YELLOWULINE "\e[4;33m"

#define COLOR(text, color) color << text << RESET

class Zombie {

	private:
		std::string	_name;

		Zombie(void);

	public:
		//Destructor
		~Zombie(void);

		//Parametric Constructor
		Zombie(std::string tmp);

		//Member Function
		void		announce(void);
};

Zombie*		newZombie(std::string name);
void		randomChump(std::string name);

#endif //ZOMBIE_HPP
