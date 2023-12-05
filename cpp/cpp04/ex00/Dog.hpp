/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:58:27 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/05 11:40:38 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {

	public:
		Dog(void);
		Dog(const Dog& src);
		Dog& operator=(const Dog& rhs);
		virtual ~Dog(void);

		virtual void	makeSound(void) const;
};

#endif
