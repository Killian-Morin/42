/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:40:05 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 16:10:11 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <list>

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

#define COLOR(text, color) color << text << RESET

template <typename T>
class MutantStack : public std::stack<T> {

	public:
		//Canonical class functions
		MutantStack(void) {}
		MutantStack(const MutantStack& src) {
			*this = src;
		}
		MutantStack&	operator=(const MutantStack& rhs) {
			if (this != &rhs)
				std::stack<T>::operator=(rhs);
			return (*this);
		}
		~MutantStack(void) {}

		//MEMBER FUNCTIONS
		typedef typename std::stack<T>::container_type::iterator 				iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		iterator				begin(void) {
			return (this->c.begin());
		}
		iterator				end(void) {
			return (this->c.end());
		}

		const_iterator			begin(void) const {
			return (this->c.begin());
		}
		const_iterator			end(void) const {
			return (this->c.end());
		}

		reverse_iterator		rbegin(void) {
			return (this->c.rbegin());
		}
		reverse_iterator		rend(void) {
			return (this->c.rend());
		}

		const_reverse_iterator	rbegin(void) const {
			return (this->c.rbegin());
		}
		const_reverse_iterator	rend(void) const {
			return (this->c.rend());
		}
};

#endif //MUTANTSTACK_HPP
