/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:37:27 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 16:09:28 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <deque>

#ifndef SHOWMSG
# define SHOWMSG 0
#endif //SHOWMSG

#define RESET "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CYAN "\e[0;36m"
#define WHITE "\e[0;37m"

#define YELLOWULINE "\e[4;33m"
#define MAGENTAULINE "\e[4;35m"
#define CYANULINE "\e[4;36m"

#define WHITEBACK "\e[47m"

#define COLOR(text, color) color << text << RESET

class Span {

	private:
		std::deque<int>	_container;
		unsigned int _n;

		Span(void);

	public:
		//Canonical class functions
		Span(const Span& src);
		Span&	operator=(const Span& rhs);
		~Span(void);

		//Parametric Constructor
		Span(unsigned int n);

		//Member Functions
		void				addNumber(int i);
		void				addNumber(std::deque<int>::iterator itBegin, std::deque<int>::iterator itEnd);

		unsigned int		shortestSpan(void) const;
		unsigned int		longestSpan(void) const;

		//Getters
		unsigned int		getN(void) const;
		std::deque<int>		getContainer(void) const;

};

//Operator overload to print Span content
std::ostream&	operator<<(std::ostream& o, const Span& span);

#endif //SPAN_HPP
