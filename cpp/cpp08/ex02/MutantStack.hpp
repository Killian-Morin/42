/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:40:05 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/22 16:02:28 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

#ifndef SHOWMSG
# define SHOWMSG 0
#endif

#define RESET "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CYAN "\e[0;36m"
#define WHITE "\e[0;37m"

#define COLOR(text, color) color << text << RESET

template < typename T, typename container = std::deque< T > >
class MutantStack : public std::stack< T, container > {

	private:

	public:
		//Canonical class functions
		MutantStack(void);
		MutantStack(const MutantStack& src);
		MutantStack&	operator=(const MutantStack& rhs);
		~MutantStack(void);

};

#include "MutantStack.tpp"

#endif
