/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:37:23 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 16:09:16 by kmorin           ###   ########.fr       */
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
/*                               MEMBER FUNCTIONS                             */
/* ************************************************************************** */

void	Span::addNumber(int i) {

	if (this->_container.size() >= this->_n)
		throw std::length_error(RED "Span is full !" WHITE);

	this->_container.push_back(i);
}

void	Span::addNumber(std::deque<int>::iterator itBegin, std::deque<int>::iterator itEnd) {

	if (this->_container.size() >= this->_n)
		throw std::length_error(RED "Span is full !" WHITE);

	this->_container.insert(this->_container.end(), itBegin, itEnd);
}

unsigned int	Span::shortestSpan(void) const {

	if (this->_container.empty())
		throw std::out_of_range(RED "Span::shortestSpan: container is empty" RESET);
	if (this->_container.size() == 1)
		throw std::out_of_range(RED "Span::shortestSpan: container only has one element" RESET);

	std::deque<int>	tmp = this->_container;
	std::sort(tmp.begin(), tmp.end());

	int	min = tmp[1] - tmp[0];

	std::deque<int>::iterator	it;
	for (it = tmp.begin(); it != tmp.end() -1; ++it) {
		if (*(it + 1) - *it < min)
			min = *(it + 1) - *it;
	}

	return (min);
}

unsigned int	Span::longestSpan(void) const {

	if (this->_container.empty())
		throw std::out_of_range(RED "Span::longestSpan: container is empty" RESET);
	if (this->_container.size() == 1)
		throw std::out_of_range(RED "Span::longestSpan: container only has one element" RESET);

	return (*std::max_element(_container.begin(), _container.end()) - *std::min_element(_container.begin(), _container.end()));
}

/* ************************************************************************** */
/*                                   GETTERS                                  */
/* ************************************************************************** */

unsigned int	Span::getN(void) const {

	return (this->_n);
}

std::deque<int>	Span::getContainer(void) const {

	return (this->_container);
}

/* ************************************************************************** */
/*                               EXTRA FUNCTION                               */
/* ************************************************************************** */

std::ostream&	operator<<(std::ostream& o, const Span& span) {

	o << COLOR("Span container size: ", MAGENTA) << COLOR(span.getN(), MAGENTAULINE) << std::endl;
	o << COLOR("Span container: ", MAGENTA);

	std::deque<int> tmp = span.getContainer();

	for (std::deque<int>::iterator it = tmp.begin(); it != tmp.end(); ++it) {
		if (it != tmp.end() - 1)
			o << *it << ", ";
		else
			o << *it << ".";
	}
	o << std::endl;
	return (o);
}
