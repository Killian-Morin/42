/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:04:16 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/05 15:28:09 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iomanip>
#include <iostream>

#define RESET "\e[0m"
#define RED "\033[31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CYAN "\e[0;36m"
#define WHITE "\033[37m"

#define COLOR(text, color) color << text << RESET

class Zombie
{
	public:
		Zombie(std::string tmp);
		~Zombie(void);

		void		announce(void);

		Zombie(void);

	private:
		std::string	_name;
};

Zombie*		newZombie(std::string name);
void		randomChump(std::string name);

#endif
