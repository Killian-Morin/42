/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:40:12 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/22 16:05:26 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

MutantStack::MutantStack(void) {

	if (SHOWMSG)
		std::cout << COLOR("Default constructor called", GREEN) << std::endl;
}

MutantStack::MutantStack(const MutantStack& src) {

	*this = src;

	if (SHOWMSG)
		std::cout << COLOR("Copy constructor called", GREEN) << std::endl;
}

template <typename T, typename container = std::deque< T > >
MutantStack&	MutantStack::operator=(const MutantStack& rhs) {

	if (this != &rhs)
		std::stack<T, container>::operator=(rhs);

	if (SHOWMSG)
		std::cout << COLOR("Assignation operator called", GREEN) << std::endl;

	return (*this);
}

MutantStack::~MutantStack(void) {

	if (SHOWMSG)
		std::cout << COLOR("Default destructor called", RED) << std::endl;
}
