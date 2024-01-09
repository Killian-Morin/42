/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:58:21 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:30:50 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"

class Cat : public AAnimal {

	private:
		Brain*	_brain;

	public:
		//Canonical class functions
		Cat(void);
		Cat(const Cat& src);
		Cat& operator=(const Cat& rhs);
		virtual ~Cat(void);

		//Overloaded herited functions
		virtual void	makeSound(void) const;

		//Getter/Setter
		std::string		getIdea(int index) const;
		void			setIdea(std::string idea, int index);
};

#endif //CAT_HPP
