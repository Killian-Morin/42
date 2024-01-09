/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:17:04 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 09:55:34 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

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


	public:
		//Constructor/Destructor
		Zombie(void);
		~Zombie(void);

		//Parametric Constructor
		Zombie(std::string tmp);

		//Member Function
		void	announce(void);

		//Setter
		void	setName(std::string name);

};

Zombie*	zombieHorde(int N, std::string name);

#endif //ZOMBIE_HPP
