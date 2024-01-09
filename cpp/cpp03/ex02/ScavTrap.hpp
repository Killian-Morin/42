/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:34:11 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 12:21:02 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	private:
		bool	_guardStatus;

	public:
		//Canonical class functions
		ScavTrap(void);
		ScavTrap(const ScavTrap& src);
		ScavTrap& operator=(const ScavTrap& rhs);
		~ScavTrap(void);

		//Parametric Constructor
		ScavTrap(std::string name);

		//Member Functions
		void	attack(const std::string& target);

		void	guardGate(void);

		//Extra function
		void	printStatus(void);
};

#endif //SCAV_TRAP_HPP
