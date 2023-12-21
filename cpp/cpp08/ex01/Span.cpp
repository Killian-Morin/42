/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:37:23 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/21 16:17:29 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

Span::Span(void) : _n(0) {

	if (SHOWMSG)
		std::cout << COLOR("Default constructor called", GREEN) << std::endl;
}

Span::Span(const Span& src) : _n(src._n) {

	if (SHOWMSG)
		std::cout << COLOR("Copy constructor called", GREEN) << std::endl;
}

Span&	Span::operator=(const Span& rhs) {

	if (this != &rhs)
		this->_n = rhs._n;

	if (SHOWMSG)
		std::cout << COLOR("Assignation operator called", GREEN) << std::endl;

	return (*this);
}

Span::~Span(void) {

	if (SHOWMSG)
		std::cout << COLOR("Defaut destructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                           PARAMETRIC CONSTRUCTOR                           */
/* ************************************************************************** */

Span::Span(unsigned int n) : _n(n) {

	if (SHOWMSG)
		std::cout << COLOR("Parametric constructor called", GREEN) << std::endl;
}

/* ************************************************************************** */
/*                              MEMBERS FUNCTIONS                             */
/* ************************************************************************** */

void	Span::addNumber(int i) {

	if (this->_container.size() >= this->_n)
		throw std::length_error(RED "Span if full !" WHITE);
	else
		this->_container.push_back(i);

}

int	Span::shortestSpan(void) const {


}

int	Span::longestSpan(void) const {

}

const unsigned int	getN(void) const {

	return (this->_n);
}

const std::deque<int<	getContainer(void) const {

	return (this->_container);
}

/* ************************************************************************** */
/*                             EXTERNAL FUNCTIONS                             */
/* ************************************************************************** */

std::ostream&	operator<<(std::ostream& o, const Span& span) {

	o << COLOR("Span container size: ", MAGENTA) << COLOR(span.getN(), MAGENTAULINE) << std::endl;
	o << COLOR("Span container: ", MAGENTA);

	std::deque<int> tmp = span.getContainer();

	for (std::deque<int>::iterator it = tmp.begin(); it != tmp.end(); it++)
		o << *it << ", ";
	o << std::endl;
}
