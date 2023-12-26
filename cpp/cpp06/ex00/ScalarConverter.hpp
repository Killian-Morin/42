/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:18:28 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/15 13:37:55 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <sstream>
#include <iomanip>

#include "Color.hpp"

#ifndef SHOWMSG
# define SHOWMSG 0
#endif

class ScalarConverter {

	private:
		//Canonical class functions
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& src);
		ScalarConverter&	operator=(const ScalarConverter& rhs);
		~ScalarConverter(void);

	public:
		//Member functions
		static void	convert(const std::string& strToConvert);

};

#endif