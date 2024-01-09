/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:59:10 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 16:10:48 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>

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

#define REDULINE "\e[4;31m"
#define YELLOWULINE "\e[4;33m"
#define MAGENTAULINE "\e[4;35m"
#define CYANULINE "\e[4;36m"

#define COLOR(text, color) color << text << RESET

class BitcoinExchange {

	private:
		std::map<std::string, float>	_database;

		BitcoinExchange(void);

		//Member Functions
		bool	checkDate(std::string& date);
		bool	checkValue(std::string& value);

		void	handleLine(std::string& date, std::string& value);

	public:
		//Canonical class functions
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange&	operator=(const BitcoinExchange& rhs);
		~BitcoinExchange(void);

		//Parametric Constructor
		BitcoinExchange(const std::string& dbFilename);

		//Member Functions
		void							run(char* av);
		void							showDatabase(void) const;
};

#endif //BITCOINEXCHANGE_HPP
