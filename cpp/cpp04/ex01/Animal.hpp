/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:52:58 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/08 11:29:31 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#include "Brain.hpp"
#include "Color.hpp"

class Animal {

	public:
		Animal(void);
		Animal(const Animal& src);
		Animal& operator=(const Animal& rhs);
		virtual ~Animal(void);

		virtual void	makeSound(void) const;

		std::string		getType(void) const;

	protected:
		std::string	_type;

};

/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */

class WrongAnimal {

	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& src);
		WrongAnimal& operator=(const WrongAnimal& rhs);
		virtual ~WrongAnimal(void);

		void	makeSound(void) const;

		std::string	getType(void) const;

	protected:
		std::string	_type;

};

#endif
