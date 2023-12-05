/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:58:21 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/05 11:22:27 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {

	public:
		Cat(void);
		Cat(const Cat& src);
		Cat& operator=(const Cat& rhs);
		virtual ~Cat(void);

		virtual void	makeSound(void) const;
};

/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */

class WrongCat : public WrongAnimal {

	public:
		WrongCat(void);
		WrongCat(const WrongCat& src);
		WrongCat& operator=(const WrongCat& rhs);
		virtual ~WrongCat(void);

		void	makeSound(void) const;
};

#endif
