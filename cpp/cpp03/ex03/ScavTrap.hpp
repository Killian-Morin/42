/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:34:11 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/01 16:36:22 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(void);
		~ScavTrap(void);
		ScavTrap(const ScavTrap& other);
		ScavTrap& operator=(const ScavTrap& rhs);

		ScavTrap(std::string name);

		void	attack(const std::string& target);

		void	guardGate(void);

		void	printStatus(void);

	private:
		bool	_guardStatus;

};

#endif