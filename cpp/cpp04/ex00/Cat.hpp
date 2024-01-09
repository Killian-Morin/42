/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:58:21 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:30:07 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {

	public:
		//Canonical class functions
		Cat(void);
		Cat(const Cat& src);
		Cat&	operator=(const Cat& rhs);
		virtual ~Cat(void);

		//Overloaded herited functions
		virtual void	makeSound(void) const;
};

/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */

class WrongCat : public WrongAnimal {

	public:
		//Canonical class functions
		WrongCat(void);
		WrongCat(const WrongCat& src);
		WrongCat&	operator=(const WrongCat& rhs);
		virtual ~WrongCat(void);

		//Overloaded herited functions
		void	makeSound(void) const;
};

#endif //CAT_HPP
