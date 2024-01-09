/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:58:27 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:30:29 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {

	public:
		//Canonical class functions
		Dog(void);
		Dog(const Dog& src);
		Dog&	operator=(const Dog& rhs);
		virtual ~Dog(void);

		//Overloaded herited functions
		virtual void	makeSound(void) const;
};

#endif //DOG_HPP
