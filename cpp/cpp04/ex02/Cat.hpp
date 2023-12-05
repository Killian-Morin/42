/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:58:21 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/05 15:10:57 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"

class Cat : public AAnimal {

	public:
		Cat(void);
		Cat(const Cat& src);
		Cat& operator=(const Cat& rhs);
		virtual ~Cat(void);

		virtual void	makeSound(void) const;
		std::string		getIdea(int index) const;
		void			setIdea(std::string idea, int index);

	private:
		Brain*	_brain;

};

/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */

class WrongCat : public WrongAAnimal {

	public:
		WrongCat(void);
		WrongCat(const WrongCat& src);
		WrongCat& operator=(const WrongCat& rhs);
		virtual ~WrongCat(void);

		void	makeSound(void) const;

};

#endif
