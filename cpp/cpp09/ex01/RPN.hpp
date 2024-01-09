/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:54:26 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 16:12:01 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>

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

class RPN {

	private:
		std::stack<int>	_container;

	public:
		//Canonical class functions
		RPN(void);
		RPN(const RPN& src);
		RPN&	operator=(const RPN& rhs);
		~RPN(void);

		//Member function
		bool	checker(const std::string& s) const;

		void	run(const std::string& s);

		int		myStoi(const std::string& s);

};

#endif //RPN_HPP
