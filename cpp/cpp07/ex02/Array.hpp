/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:54:07 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 16:07:44 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <sstream>
#include <stdexcept>

#define RESET "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CYAN "\e[0;36m"
#define WHITE "\e[0;37m"

#define COLOR(text, color) color << text << RESET

#ifndef SHOWMSG
# define SHOWMSG 0
#endif //SHOWMSG

template <typename T>
class Array {

	private:
		T*				_array;
		unsigned int	_len;

	public:
		//Canonical class functions
		Array(void);
		Array(const Array& src);
		Array&	operator=(const Array& rhs);
		~Array(void);

		//Parametric Constructor
		Array(unsigned int n);

		//Member Functions
		T&	operator[](unsigned int n);

		unsigned int	size(void) const;

		//Exceptions class
		class OutOfBoundsException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#include "Array.tpp"

#endif //ARRAY_HPP
