/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:42:21 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/05 15:35:48 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <string>
#include <iostream>
#include <fstream>

#define RESET "\e[0m"
#define RED "\033[31m"
#define GREEN "\e[0;32m"
#define BLUE "\e[0;34m"
#define WHITE "\033[37m"

#define COLOR(text, color) color << text << RESET

//No default constructor since I didn't create a setter for the ≠ attributs
class Replace
{
	public:
		Replace(std::string file, std::string s1, std::string s2);
		~Replace(void);

		void	replace(void);

	private:
		std::string	_infile;
		std::string	_outfile;
		std::string	_s1;
		std::string	_s2;
};

#endif
