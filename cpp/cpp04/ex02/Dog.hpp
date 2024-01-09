/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:58:27 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:30:54 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"

class Dog : public AAnimal {

	private:
		Brain*	_brain;

	public:
		//Canonical class functions
		Dog(void);
		Dog(const Dog& src);
		Dog& operator=(const Dog& rhs);
		virtual ~Dog(void);

		//Overloaded herited functions
		virtual void	makeSound(void) const;

		//Getter/Setter
		std::string		getIdea(int index) const;
		void			setIdea(std::string idea, int index);
};

#endif //DOG_HPP
