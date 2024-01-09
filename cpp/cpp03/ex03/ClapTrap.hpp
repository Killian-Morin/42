/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:55:56 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 14:01:34 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>

#ifndef SHOWMSG
# define SHOWMSG 0
#endif //SHOWMSG

#define RESET "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CYAN "\e[0;36m"
#define WHITE "\e[0;37m"

#define YELLOWBOLD "\e[1;33m"

#define REDULINE "\e[4;31m"
#define GREENULINE "\e[4;32m"
#define YELLOWULINE "\e[4;33m"
#define BLUEULINE "\e[4;34m"
#define MAGENTAULINE "\e[4;35m"
#define CYANULINE "\e[4;36m"
#define WHITEULINE "\e[4;37m"

#define YELLOWBACK "\e[43m"
#define CYANBACK "\e[46m"
#define WHITEBACK "\e[47m"

#define COLOR(text, color) color << text << RESET

class ClapTrap {

	protected:
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
		std::string		_name;

	public:
		//Canonical class functions
		ClapTrap(void);
		ClapTrap(const ClapTrap& src);
		ClapTrap& operator=(const ClapTrap& rhs);
		~ClapTrap(void);

		//Parametric Constructor
		ClapTrap(std::string name);

		//Member Functions
		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		//Getters/Setter
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;

		void			setName(std::string name);

		//Extra function
		void			printStatus(void);
};

#endif //CLAP_TRAP_HPP
