/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:52:58 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 14:32:30 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#include "Brain.hpp"
#include "Color.hpp"

class AAnimal {

	protected:
		std::string	_type;

	public:
		//Canonical class functions
		AAnimal(void);
		AAnimal(const AAnimal& src);
		AAnimal&	operator=(const AAnimal& rhs);
		virtual ~AAnimal(void);

		//Member Function
		virtual void	makeSound(void) const = 0;

		//Getter
		std::string	getType(void) const;
};

#endif //ANIMAL_HPP
