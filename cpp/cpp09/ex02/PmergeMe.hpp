/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:54:09 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 14:03:56 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <deque>
#include <vector>
#include <utility>
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

#define GREENULINE "\e[4;32m"
#define BLUEULINE "\e[4;34m"
#define MAGENTAULINE "\e[4;35m"

#define COLOR(text, color) color << text << RESET

class PmergeMe {

	private:
		std::deque<int>		_d;
		std::vector<int>	_v;

	public:
		//Canonical class functions
		PmergeMe(void);
		PmergeMe(const PmergeMe& src);
		PmergeMe&	operator=(const PmergeMe& rhs);
		~PmergeMe(void);

		//Member Functions
		static bool		checker(char **av);
		static void		printTime(double timeDeque, double timeVector, int nb);

		//DEQUE
		void			initDeque(char **av);
		void			printDeque(bool when);
		void			sortDeque(void);
		int				binarySearchDeque(std::deque<int> d, int elementToSearch);

		//VECTOR
		void			initVector(char **av);
		void			printVector(bool when);
		void			sortVector(void);
		int				binarySearchVector(std::vector<int> v, int elementToSearch);
};

class Pair {

	public:
		Pair(const Pair& src);
		Pair&	operator=(const Pair& rhs);
		~Pair(void);

		Pair(int first, int second);

		int	_first;
		int	_second;

	private:
		Pair(void);
};

#endif //PMERGEME_HPP
