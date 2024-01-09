/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:54:18 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 16:11:56 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

RPN::RPN(void) {

	if (SHOWMSG)
		std::cout << COLOR("Default constructor called", GREEN) << std::endl;
}

RPN::RPN(const RPN& src) {

	this->_container = src._container;

	if (SHOWMSG)
		std::cout << COLOR("Copy constructor called", GREEN) << std::endl;
}

RPN&	RPN::operator=(const RPN& rhs) {

	if (this != &rhs)
		this->_container = rhs._container;

	if (SHOWMSG)
		std::cout << COLOR("Assignation operator called", GREEN) << std::endl;

	return (*this);
}

RPN::~RPN(void) {

	while (!this->_container.empty())
		this->_container.pop();

	if (SHOWMSG)
		std::cout << COLOR("Defaut destructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                               MEMBER FUNCTIONS                             */
/* ************************************************************************** */

bool	RPN::checker(const std::string& s) const {

	if (s.empty() || s.find_first_not_of(' ') == s.npos) {
		std::cout << COLOR("Error: expression is empty :(", RED) << std::endl;
		return (false);
	}

	if (s.find_first_not_of("0123456789 +-/*") != s.npos) {
		std::cout << COLOR("Error: expression contains invalid characters.", RED) << std::endl;
		return (false);
	}

	if (s.find_first_of("+-/*") == s.npos) {
		std::cout << COLOR("Error: no operator in the expression.", RED) << std::endl;
		return (false);
	}

	if (s.length() < 5) {
		std::cout << COLOR("Error: expression is invalid (too short).", RED) << std::endl;
		return (false);
	}

	if (s[s.length() - 1] != '+' && s[s.length() - 1] != '-' && s[s.length() - 1] != '*' && s[s.length() - 1] != '/') {
		std::cout << COLOR("Error: operator must be the last character of expression.", RED) << std::endl;
		return (false);
	}

	if (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/' || s[0] == ' ') {
		std::cout << COLOR("Error: number must be the first character of expression.", RED) << std::endl;
		return (false);
	}

	//since spaces will always be on a even index
	for (size_t i = 0; i < s.length(); i++) {

		if (i % 2 == 0) {

			if (!isdigit(s[i]) && s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/') {
				std::cout << COLOR("Error: expression is invalid (digit or operator not in correct place).", RED) << std::endl;
				return (false);
			}
			if (isdigit(s[i + 1])) {
				std::cout << COLOR("Error: expression contains a number > 10.", RED) << std::endl;
				return (false);
			}
		}
		else {
			if (s[i] != ' ') {
				std::cout << COLOR("Error: expression is invalid (space not in correct place).", RED) << std::endl;
				return (false);
			}
		}
	}

	for (size_t i = 0; i < s.length(); i++) {

		if (s[i] == '0') {

			if (s[i + 2] == '/') {
				std::cout << COLOR("Error: division by zero.", RED) << std::endl;
				return (false);
			}
		}
	}

	return (true);
}

void	RPN::run(const std::string& s) {

	size_t i = 0;
	while (i < s.length()) {

		if (s[i] == ' ') {
			i++;
			continue;
		}

		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {

			if (this->_container.size() < 2) {
				std::cout << COLOR("Error: not enough numbers or operands.", RED) << std::endl;

				while (!this->_container.empty())
					this->_container.pop();

				return ;
			}

			int	rhs = this->_container.top();
			this->_container.pop();
			int	lhs = this->_container.top();
			this->_container.pop();

			if (s[i] == '+')
				this->_container.push(lhs + rhs);
			else if (s[i] == '-')
				this->_container.push(lhs - rhs);
			else if (s[i] == '*')
				this->_container.push(lhs * rhs);
			else if (s[i] == '/')
				this->_container.push(lhs / rhs);

		}
		else
			this->_container.push(myStoi(&s[i]));

		i++;
	}

	if (this->_container.size() > 1) {
		std::cout << COLOR("Error: too many numbers or operands.", RED) << std::endl;

		while (!this->_container.empty())
			this->_container.pop();

		return ;
	}
	std::cout << COLOR(this->_container.top(), MAGENTA) << std::endl;
}

int	RPN::myStoi(const std::string& s) {

	int	i;
	std::stringstream	ss(s);

	ss >> i;

	if (ss.fail()) {
		std::cout << COLOR("Error: conversion failed.", RED) << std::endl;

		while (!this->_container.empty())
			this->_container.pop();

		exit(EXIT_FAILURE);
	}

	return (i);
}
