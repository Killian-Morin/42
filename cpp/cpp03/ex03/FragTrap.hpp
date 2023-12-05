/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:40:53 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/01 13:24:04 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(void);
		~FragTrap(void);
		FragTrap(const FragTrap& other);
		FragTrap& operator=(const FragTrap& rhs);

		FragTrap(std::string name);

		void	highFivesGuys(void);

		void	printStatus(void);

};

#endif