/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:17:04 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/05 15:31:12 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

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

		void	announce(void);

		void	setName(std::string name);

		Zombie(void);

	private:
		std::string	_name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif
