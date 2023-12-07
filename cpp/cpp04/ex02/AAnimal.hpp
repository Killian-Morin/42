/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:52:58 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/07 13:34:26 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#include "Brain.hpp"
#include "Color.hpp"

class AAnimal {

	public:
		AAnimal(void);
		AAnimal(const AAnimal& src);
		AAnimal& operator=(const AAnimal& rhs);
		virtual ~AAnimal(void);

		virtual void	makeSound(void) const = 0;

		std::string	getType(void) const;

	protected:
		std::string	_type;

};

/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */

class WrongAAnimal {

	public:
		WrongAAnimal(void);
		WrongAAnimal(const WrongAAnimal& src);
		WrongAAnimal& operator=(const WrongAAnimal& rhs);
		virtual ~WrongAAnimal(void);

		void	makeSound(void) const;

		std::string	getType(void) const;

	protected:
		std::string	_type;

};

#endif
