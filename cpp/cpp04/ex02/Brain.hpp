/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:34:10 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/05 15:10:01 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "AAnimal.hpp"

class Brain {
	public:
		Brain(void);
		Brain(const Brain& src);
		Brain&	operator=(const Brain& rhs);
		~Brain(void);

		std::string	getIdea(int index) const;
		void		setIdea(std::string idea, int index);

	private:
		std::string	ideas[100];

};

#endif
