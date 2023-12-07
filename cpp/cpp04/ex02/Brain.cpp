/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:34:08 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/07 13:35:15 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/* ************************************************************************** */
/*                  CANONIC METHODS and SPECIAL CONSTRUCTORS                  */
/* ************************************************************************** */

Brain::Brain(void)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "No idea";

	std::cout << COLOR("Brain 🧠", WHITE);
	std::cout << COLOR(" Default constructor", BLUE) << std::endl;
}

Brain::Brain(const Brain& src)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];

	std::cout << COLOR("Brain 🧠", WHITE);
	std::cout << COLOR(" Copy constructor", BLUE) << std::endl;
}

Brain&	Brain::operator=(const Brain& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
	}

	std::cout << COLOR("Brain 🧠", WHITE);
	std::cout << COLOR(" assignement operator called", BLUE) << std::endl;

	return (*this);
}

Brain::~Brain(void)
{
	std::cout << COLOR("Brain 🧠", WHITE);
	std::cout << COLOR(" Default destructor", RED) << std::endl;
}

/* ************************************************************************** */
/*                              MEMBERS FUNCTIONS                             */
/* ************************************************************************** */

std::string	Brain::getIdea(int index) const
{
	if (index < 0 || index > 100)
	{
		std::cout << COLOR("Sorry, index is not within scope (0-100). ", RED);
		return ("");
	}
	return (this->ideas[index]);
}

void	Brain::setIdea(std::string idea, int index)
{
	if (index < 0 || index > 100)
	{
		std::cout << COLOR("Sorry, index is not within scope (0-100).", RED) << std::endl;
		return ;
	}
	this->ideas[index] = idea;
}
