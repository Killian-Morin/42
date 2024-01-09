/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:54:07 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 16:12:57 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

PmergeMe::PmergeMe(void) {

	if (SHOWMSG)
		std::cout << COLOR("Default constructor called", GREEN) << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& src) {

	this->_d = src._d;
	this->_v = src._v;

	if (SHOWMSG)
		std::cout << COLOR("Copy constructor called", GREEN) << std::endl;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& rhs) {

	if (this != &rhs) {
		this->_d = rhs._d;
		this->_v = rhs._v;
	}

	if (SHOWMSG)
		std::cout << COLOR("Assignation operator called", GREEN) << std::endl;

	return (*this);
}

PmergeMe::~PmergeMe(void) {

	if (SHOWMSG)
		std::cout << COLOR("Defaut destructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                              MEMBER FUNCTIONS                             */
/* ************************************************************************** */

bool	PmergeMe::checker(char **av) {

	for (int i = 0; av[i]; i++) {

		for (int j = 0; av[i][j]; j++) {

			if (!isdigit(av[i][j])) {
				std::cout << COLOR("Error: invalid input", RED) << std::endl;
				return (false);
			}
		}

		std::stringstream	ss(av[i]);
		int					n;

		ss.clear();
		ss >> n;

		if (ss.fail()) {
			std::cout << COLOR("Error: non integer input", RED) << std::endl;
			return (false);
		}

		// for (int j = i + 1; av[j]; j++) {

		// 	if (std::atoi(av[i]) == std::atoi(av[j])) {
		// 		std::cout << COLOR("Error: duplicate input", RED) << std::endl;
		// 		return (false);
		// 	}
		// }
	}

	return (true);
}

void	PmergeMe::printTime(double timeDeque, double timeVector, int nb) {

	// std::cout << GREEN << "Time to process a range of " << nb << \
	// 	" elements with std::deque : " << std::fixed << COLOR(timeDeque, GREENULINE) << COLOR(" us", GREEN) << std::endl;

	// std::cout << MAGENTA << "Time to process a range of " << nb << \
	// 	" elements with std::vector : " << std::fixed << COLOR(timeVector, MAGENTAULINE) << COLOR(" us", MAGENTA) << std::endl;

	std::cout << GREEN << "Time to process a range of " << nb << \
		" elements with std::deque : " << std::fixed << COLOR(1000 * timeDeque, GREENULINE) << COLOR(" ms", GREEN) << std::endl;

	std::cout << MAGENTA << "Time to process a range of " << nb << \
		" elements with std::vector : " << std::fixed << COLOR(1000 * timeVector, MAGENTAULINE) << COLOR(" ms", MAGENTA) << std::endl;
}

/* ************************************************************************** */
/*                                    DEQUE                                   */
/* ************************************************************************** */

void	PmergeMe::initDeque(char **av) {

	for (int i = 0; av[i]; i++) {
		this->_d.push_back(std::atoi(av[i]));
	}
}

void	PmergeMe::printDeque(bool when) {

	if (when)
		std::cout << COLOR("Before: ", YELLOW);
	else
		std::cout << COLOR("After: ", CYAN);

	for (std::deque<int>::iterator it = _d.begin(); it != _d.end(); it++) {
		std::cout << *it << " ";
	}

	std::cout << std::endl;
}

void	PmergeMe::sortDeque(void) {

	std::deque<Pair>	dPairs;

	int	last = 0;

	for (std::deque<int>::iterator	it = _d.begin(); it != _d.end(); it += 2) {

		if (it + 1 == _d.end()) {
			last = *it;
			break;
		}
		dPairs.push_back(Pair(*it, *(it + 1)));
	}

	for (std::deque<Pair>::iterator it = dPairs.begin(); it != dPairs.end(); it++) {

		if (it->_first < it->_second)
			std::swap(it->_first, it->_second);
	}

	std::deque<Pair>	dPairsSort;
	for (std::deque<Pair>::iterator it = dPairs.begin(); it != dPairs.end(); it ++) {

		if (dPairsSort.empty()) {
			dPairsSort.push_back(*it);
			continue;
		}

		for (std::deque<Pair>::iterator it2 = dPairsSort.begin(); it2 != dPairsSort.end(); it2++) {

			if (it->_first < it2->_first) {
				dPairsSort.insert(it2, *it);
				break;
			}
			if (it2 + 1 == dPairsSort.end()) {
				dPairsSort.push_back(*it);
				break;
			}
		}
	}

	std::deque<int>	dSort;
	dSort.push_back(dPairsSort[0]._second);
	dSort.push_back(dPairsSort[0]._first);
	for (std::deque<Pair>::iterator it = dPairsSort.begin() + 1; it != dPairsSort.end(); it++) {

		dSort.push_back(it->_first);

		int	index = binarySearchDeque(dSort, it->_second);
		dSort.insert(dSort.begin() + index, it->_second);
	}

	if (last) {
		int	index = binarySearchDeque(dSort, last);
		dSort.insert(dSort.begin() + index, last);
	}

	_d = dSort;
}

int	PmergeMe::binarySearchDeque(std::deque<int> d, int elementToSearch) {

	int	left = 0;
	int	right = d.size() - 1;

	while (left <= right) {
		int	mid = (left + right) / 2;

		if (elementToSearch < d[mid])
			right = mid - 1;
		else if (elementToSearch > d[mid])
			left = mid + 1;
		else
			return (mid);
	}

	return (left);
}

/* ************************************************************************** */
/*                                   VECTOR                                   */
/* ************************************************************************** */

void	PmergeMe::initVector(char **av) {

	for (int i = 0; av[i]; i++) {
		this->_v.push_back(std::atoi(av[i]));
	}
}

void	PmergeMe::printVector(bool when) {

	if (when)
		std::cout << COLOR("Before: ", YELLOW);
	else
		std::cout << COLOR("After: ", CYAN);

	for (std::vector<int>::iterator it = _v.begin(); it != _v.end(); it++) {
		std::cout << *it << " ";
	}

	std::cout << std::endl;
}

void	PmergeMe::sortVector(void) {

	std::vector<Pair>	vPairs;

	int	last = 0;

	for (std::vector<int>::iterator it = _v.begin(); it != _v.end(); it += 2) {

		if (it + 1 == _v.end()) {
			last = *it;
			break;
		}
		vPairs.push_back(Pair(*it, *(it + 1)));
	}

	for (std::vector<Pair>::iterator it = vPairs.begin(); it != vPairs.end(); it++) {

		if (it->_first < it->_second)
			std::swap(it->_first, it->_second);
	}

	std::vector<Pair>	vPairsSort;
	for (std::vector<Pair>::iterator it = vPairs.begin(); it != vPairs.end(); it++) {

		if (vPairsSort.empty()) {
			vPairsSort.push_back(*it);
			continue;
		}

		for (std::vector<Pair>::iterator it2 = vPairsSort.begin(); it2 != vPairsSort.end(); it2++) {

			if (it->_first < it2->_first) {
				vPairsSort.insert(it2, *it);
				break;
			}
			if (it2 + 1 == vPairsSort.end()) {
				vPairsSort.push_back(*it);
				break;
			}
		}
	}

	std::vector<int>	vSort;
	vSort.push_back(vPairsSort[0]._second);
	vSort.push_back(vPairsSort[0]._first);
	for (std::vector<Pair>::iterator it = vPairsSort.begin() + 1; it != vPairsSort.end(); it++) {

		vSort.push_back(it->_first);

		int	index = binarySearchVector(vSort, it->_second);
		vSort.insert(vSort.begin() + index, it->_second);
	}

	if (last) {
		int	index = binarySearchVector(vSort, last);
		vSort.insert(vSort.begin() + index, last);
	}

	_v = vSort;
}

int	PmergeMe::binarySearchVector(std::vector<int> v, int elementToSearch) {

	int	left = 0;
	int	right = v.size() - 1;

	while (left <= right) {
		int	mid = (left + right) / 2;

		if (elementToSearch < v[mid])
			right = mid - 1;
		else if (elementToSearch > v[mid])
			left = mid + 1;
		else
			return (mid);
	}

	return (left);
}

/* ************************************************************************** */
/*                                    PAIR                                    */
/* ************************************************************************** */

Pair::Pair(void) {

}

Pair::Pair(int first, int second) : _first(first), _second(second) {

}

Pair::Pair(const Pair& src) {

	this->_first = src._first;
	this->_second = src._second;
}

Pair&	Pair::operator=(const Pair& rhs) {

	if (this != &rhs) {
		this->_first = rhs._first;
		this->_second = rhs._second;
	}

	return (*this);
}

Pair::~Pair(void) {

}
