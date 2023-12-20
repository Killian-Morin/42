/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:28:20 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/20 16:22:41 by kmorin           ###   ########.fr       */
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
#define MAGENTAULINE "\e[4;35m"
#define CYANULINE "\e[4;36m"

#define COLOR(text, color) color << text << RESET

//Template Function
template <typename T>
void	easyfind(T&, int i);

//Exception class
class ParameterNotFoundException : public std::exception {
	public:
		virtual const char* what() const throw();
};

#include "easyfind.tpp"

#endif
