/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:54:04 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/02 16:12:44 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

double	Deque(char **av) {

	PmergeMe	d;
	clock_t		start, end;

	d.initDeque(av);

	d.printDeque(1);

	start = clock();
	d.sortDeque();
	end = clock();

	d.printDeque(0);

	return ((double)(end - start) / CLOCKS_PER_SEC);

}

double	Vector(char **av) {

	PmergeMe	v;
	clock_t		start, end;

	v.initVector(av);

	v.printVector(1);

	start = clock();
	v.sortVector();
	end = clock();

	v.printVector(0);

	return ((double)(end - start) / CLOCKS_PER_SEC);

}

int	main(int ac, char **av) {

	if (ac < 3) {
		std::cout << COLOR("Usage: ./PmergeMe [nb] [nb] ...", RED) << std::endl;
		return (1);
	}

	if (!PmergeMe::checker(av + 1))
		return (1);

	double	timeDeque = Deque(av + 1);

	double	timeVector = Vector(av + 1);

	PmergeMe::printTime(timeDeque, timeVector, ac - 1);

	return (0);
}
