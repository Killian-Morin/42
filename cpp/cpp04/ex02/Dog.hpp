/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:58:27 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/05 15:10:51 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"

class Dog : public AAnimal {

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
