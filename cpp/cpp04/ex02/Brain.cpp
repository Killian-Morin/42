/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:34:08 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 14:38:31 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

Brain::Brain(void) {

	for (int i = 0; i < 100; i++)
		this->ideas[i] = "No idea";

	if (SHOWMSG)
		std::cout << COLOR("Brain 🧠", WHITE) << COLOR(" Default constructor called", GREEN) << std::endl;
}

Brain::Brain(const Brain& src) {

	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];

	if (SHOWMSG)
		std::cout << COLOR("Brain 🧠", WHITE) << COLOR(" Copy constructor called", GREEN) << std::endl;
}

Brain&	Brain::operator=(const Brain& rhs) {

	if (this != &rhs) {
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
	}

	if (SHOWMSG)
		std::cout << COLOR("Brain 🧠", WHITE) << COLOR(" Assignement operator called", GREEN) << std::endl;

	return (*this);
}

Brain::~Brain(void) {

	if (SHOWMSG)
		std::cout << COLOR("Brain 🧠", WHITE) << COLOR(" Default destructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                                GETTER/SETTER                               */
/* ************************************************************************** */

std::string	Brain::getIdea(int index) const {

	if (index < 0 || index > 100) {
		std::cout << COLOR("Sorry, index is not within scope (0-100). ", RED);
		return ("");
	}
	return (this->ideas[index]);
}

void	Brain::setIdea(std::string idea, int index) {

	if (index < 0 || index > 100) {
		std::cout << COLOR("Sorry, index is not within scope (0-100).", RED) << std::endl;
		return ;
	}
	this->ideas[index] = idea;
}
