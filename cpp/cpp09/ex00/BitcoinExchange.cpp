/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:58:54 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 16:10:25 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

//In private, that way forced to instantiate by providing the database file
BitcoinExchange::BitcoinExchange(void) {

	if (SHOWMSG)
		std::cout << COLOR("Default constructor called", GREEN) << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {

	this->_database = src._database;

	if (SHOWMSG)
		std::cout << COLOR("Copy constructor called", GREEN) << std::endl;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rhs) {

	if (this != &rhs)
		this->_database = rhs._database;

	if (SHOWMSG)
		std::cout << COLOR("Assignation operator called", GREEN) << std::endl;

	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {

	if (SHOWMSG)
		std::cout << COLOR("Defaut destructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                           PARAMETRIC CONSTRUCTOR                           */
/* ************************************************************************** */

BitcoinExchange::BitcoinExchange(const std::string& dbFilename) {

	std::ifstream	dbFile(dbFilename);
	if (!dbFile.is_open() && dbFile.good()) {
		std::cout << COLOR("Error: could not open ", RED) << COLOR(dbFilename, REDULINE) << COLOR(".", RED) << std::endl;
		exit(EXIT_FAILURE);
	}

	if (dbFile.peek() == std::ifstream::traits_type::eof()) {
		dbFile.close();
		std::cout << COLOR("Error: ", RED) << COLOR(dbFilename, REDULINE) << COLOR(" is empty.", RED)  << std::endl;
		exit(EXIT_FAILURE);
	}

	std::string	line;
	std::string	date;
	std::string	value;

	std::getline(dbFile, line);
	while (std::getline(dbFile, line)) {
		date = line.substr(0, line.find(','));

		value = line.substr(line.find(',') + 1);

		this->_database[date] = std::atof(value.c_str());
	}

	dbFile.close();

	if (SHOWMSG)
		std::cout << COLOR("Parametric constructor called", GREEN) << std::endl;
}

/* ************************************************************************** */
/*                               MEMBER FUNCTIONS                             */
/* ************************************************************************** */

bool	BitcoinExchange::checkDate(std::string& date) {

	bool	signal = true;

	if (date.length() != 10 && date[4] != '-' && date[7] != '-')
		signal = false;

	std::string	year = date.substr(0, 4);
	if (year.find_first_not_of("0123456789") != year.npos)
		signal = false;

	std::string	month = date.substr(5, 2);
	if (month.find_first_not_of("0123456789") != month.npos)
		signal = false;
	if (std::atoi(month.c_str()) < 1 || std::atoi(month.c_str()) > 12)
		signal = false;

	std::string	day = date.substr(8, 2);
	if (day.find_first_not_of("0123456789") != day.npos)
		signal = false;

	if ((!month.compare("01") || !month.compare("03") || !month.compare("05") || !month.compare("07") || \
		!month.compare("08") || !month.compare("10") || !month.compare("12"))) {
			if (std::atoi(day.c_str()) < 1 || std::atoi(day.c_str()) > 31)
				signal = false;
		}

	if ((!month.compare("04") || !month.compare("06") || !month.compare("09") || !month.compare("11"))) {
		if (std::atoi(day.c_str()) < 1 || std::atoi(day.c_str()) > 30)
			signal = false;
	}

	if (!month.compare("02") && (std::atoi(day.c_str()) < 1 || std::atoi(day.c_str()) > 28))
		signal = false;

	if (!signal) {
		std::cout << COLOR("Error: not a valid date format => ", CYAN) << COLOR(date, CYANULINE) << std::endl;
	}
	return (signal);
}

bool	BitcoinExchange::checkValue(std::string& value) {

	if (value[0] == '.' || value[value.length() - 1] == '.') {
		std::cout << COLOR("Error: '.' cannot be the first or last character => ", YELLOW) << COLOR(value, YELLOWULINE) << std::endl;
		return (false);
	}

	if (std::count(value.begin(), value.end(), '.') > 1 || std::count(value.begin(), value.end(), '-') > 1) {
		std::cout << COLOR("Error: cannot have more than one '.' or '-' => ", YELLOW) << COLOR(value, YELLOWULINE) << std::endl;
		return (false);
	}

	if (value.empty()) {
		std::cout << COLOR("Error: value cannot be empty.", YELLOW) << std::endl;
		return (false);
	}

	if (value.find_first_not_of("0123456789-.") != value.npos) {
		std::cout << COLOR("Error: value not a number => ", YELLOW) << COLOR(value, YELLOWULINE) << std::endl;
		return (false);
	}

	if (std::count(value.begin(), value.end(), '-') == 1 && value.find('-') != 0) {
		std::cout << COLOR("Error: '-' must be the first character => ", YELLOW) << COLOR(value, YELLOWULINE) << std::endl;
		return (false);
	}

	float	f = std::atof(value.c_str());
	if (f < 0) {
		std::cout << COLOR("Error: not a positive number => ", YELLOW) << COLOR(value, YELLOWULINE) << std::endl;
		return (false);
	}
	else if (f > 1000) {
		std::cout << COLOR("Error: too large a number => ", YELLOW) << COLOR(value, YELLOWULINE) << std::endl;
		return (false);
	}
	return (true);
}

void	BitcoinExchange::handleLine(std::string& date, std::string& value) {

	if (checkDate(date) && checkValue(value)) {

		float	rate, result;
		std::map<std::string, float>::iterator	it = this->_database.find(date);

		if (it != this->_database.end())
			rate = this->_database[date];
		else {
			std::map<std::string, float>::iterator	lower = this->_database.lower_bound(date);
			if (lower == this->_database.end() || lower == this->_database.begin()) {
				std::cout << COLOR("Error: could not find an exchange rate for => ", YELLOW) << COLOR(date, YELLOWULINE) << std::endl;
				return ;
			}
			lower--;
			rate = lower->second;
		}

		result = rate * std::atof(value.c_str());
		std::cout << COLOR(date + " => " + value + " = ", BLUE) << COLOR(result, BLUE) << std::endl;
	}
}

void	BitcoinExchange::run(char* av) {

	std::ifstream	file(av);
	if (!file.is_open() && file.good()) {
		std::cout << COLOR("Error: could not open ", RED) << COLOR(av, REDULINE) << COLOR(".", RED) << std::endl;
		exit(EXIT_FAILURE);
	}

	if (file.peek() == std::ifstream::traits_type::eof()) {
		file.close();
		std::cout << COLOR("Error: ", RED) << COLOR(av, REDULINE) << COLOR(" is empty.", RED)  << std::endl;
		exit(EXIT_FAILURE);
	}

	std::string	line;
	std::string	date;
	std::string	value;

	std::getline(file, line);
	while (std::getline(file, line)) {

		if (line.find('|') == line.npos || line.find('|') == line.length() - 1) {
			std::cout << COLOR("Error: bad input => ", MAGENTA) << COLOR(line, MAGENTAULINE) << std::endl;
			continue;
		}

		date = line.substr(0, line.find('|') - 1);

		value = line.substr(line.find('|') + 2);

		handleLine(date, value);
	}

	file.close();
}

void	BitcoinExchange::showDatabase(void) const {

	for (std::map<std::string, float>::const_iterator it = this->_database.begin(); it != this->_database.end(); it++) {
		std::cout << GREEN << "[ " << it->first << " ] | [ " << it->second << " ]" << RESET << std::endl;
	}
}
