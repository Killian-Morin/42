/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:34:10 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 14:10:20 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain {

	private:
		std::string	ideas[100];

	public:
		//Canonical class functions
		Brain(void);
		Brain(const Brain& src);
		Brain&	operator=(const Brain& rhs);
		~Brain(void);

		//Getter/Setter
		std::string	getIdea(int index) const;
		void		setIdea(std::string idea, int index);
};

#endif //BRAIN_HPP
