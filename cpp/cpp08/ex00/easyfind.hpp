/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:28:20 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/26 15:59:02 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>
#include <deque>
#include <list>

#define RESET "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CYAN "\e[0;36m"
#define WHITE "\e[0;37m"

#define GREENULINE "\e[4;32m"
#define YELLOWULINE "\e[4;33m"
#define BLUEULINE "\e[4;34m"
#define MAGENTAULINE "\e[4;35m"
#define CYANULINE "\e[4;36m"

#define COLOR(text, color) color << text << RESET

//Exception class
class ParameterNotFoundException : public std::exception {
	public:
		virtual const char* what() const throw() {
			
			return (RED "Couldn't find the value in the array !" RESET);
		}
};

//Template Function
/*
	method with an iterator, the one used here
		create an iterator using, the template type that will be replaced by the type of the container
		this iterator takes the result of the find algorithm
		find return an iterator to end() if it didn't find a corresponding element
		find return an iterator to the corresponding element of the container

	method with ternary operand that compares the iterator that is returned by find
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

#endif
