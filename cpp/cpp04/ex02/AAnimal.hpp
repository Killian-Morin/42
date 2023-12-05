/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:52:58 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/05 15:09:20 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#include "Brain.hpp"

#define RESET "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CYAN "\e[0;36m"
#define WHITE "\e[0;37m"

#define CYANBACKG "\e[46m"

#define COLOR(text, color) color << text << RESET

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
