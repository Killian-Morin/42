/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:58:27 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/05 14:12:59 by kmorin           ###   ########.fr       */
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
		std::string		getIdea(int index) const;
		void			setIdea(std::string idea, int index);

	private:
		Brain*	_brain;

};

#endif
