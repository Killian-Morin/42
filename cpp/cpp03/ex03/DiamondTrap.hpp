/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:22:06 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/01 11:28:08 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

/*
With the virtual inheritance we obtain a diamond form:

        ClapTrap
       /     \
	  /       \
  ScavTrap   FragTrap
       \     /
	    \   /
      DiamondTrap

Without the virtual inheritance, each parent of DiamondTrap
have their own instance of their parent: ClapTrap:

  ClapTrap     ClapTrap
      |          |
	  |          |
  ScavTrap   FragTrap
       \     /
	    \   /
      DiamondTrap

*/

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		~DiamondTrap();
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap& operator=(const DiamondTrap& rhs);

		DiamondTrap(std::string name);

		void	attack(const std::string& target);

		void	whoAmI(void);

	private:
		std::string	_name;
};

#endif
