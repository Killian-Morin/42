/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:40:53 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 12:40:12 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

	public:
		//Canonical class functions
		FragTrap(void);
		FragTrap(const FragTrap& src);
		FragTrap& operator=(const FragTrap& rhs);
		~FragTrap(void);

		//Parametric Constructor
		FragTrap(std::string name);

		//Member Function
		void	highFivesGuys(void);

		//Extra function
		void	printStatus(void);

};

#endif //FRAG_TRAP_HPP
