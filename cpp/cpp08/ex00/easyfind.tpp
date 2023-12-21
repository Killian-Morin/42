/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:28:19 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/21 14:36:26 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

/* ************************************************************************** */
/*                             TEMPLATE FUNCTION                              */
/* ************************************************************************** */

/*
	method with an iterator, the one that I use here
		create an iterator using, for the moment the template type,
			that will be replaced by the type of the container
		this iterator takes the result of the find algorithm
		find return an iterator to end() if it didn't find a corresponding element
		find return an iterator to the corresponding element of the container

	method with ternary operand
*/
template <typename T>
void	easyfind(T& container, int value) {

	typename T::iterator	it = std::find(container.begin(), container.end(), value);

	if (it != container.end())
		std::cout << COLOR("The value ", GREEN) << COLOR(value, GREENULINE) << \
			COLOR(" is present in the container.", GREEN) << std::endl;
	else
		throw ParameterNotFoundException();

	// std::find(container.begin(), container.end(), value) != container.end() ?
		// std::cout << COLOR("The value ", GREEN) << COLOR(value, GREENULINE) << COLOR(" is present in the container.", GREEN) << std::endl :
		// throw ParameterNotFoundException();
}

/* ************************************************************************** */
/*                              EXCEPTION CLASS                               */
/* ************************************************************************** */

const char*	ParameterNotFoundException::what() const throw() {

	return (RED "Couldn't find the value in the array !" RESET);
}
