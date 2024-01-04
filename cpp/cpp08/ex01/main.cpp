/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:37:18 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/04 12:04:37 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void	hugeAmountAnnoying(void) {

	std::cout << COLOR("Span addNumber, overload taking int as parameter test. ", BLUE) << std::endl;

	Span	test(15000);

	try {
		for (int i = 0; i < 15000; i++)
			test.addNumber(i);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << test << std::endl;
	std::cout << COLOR("The shortest span is ", CYAN) << COLOR(test.shortestSpan(), CYANULINE) << COLOR(".", CYAN) << std::endl;
	std::cout << COLOR("The longest span is ", YELLOW) << COLOR(test.longestSpan(), YELLOWULINE) << COLOR(".", YELLOW) << std::endl;
}

void	hugeAmountOpti(void) {

	std::cout << COLOR("Span addNumber, overload taking two iterators as parameters test: ", GREEN) << std::endl;

	std::deque<int>	tmp(15000);
	std::srand(time(NULL));
	std::generate(tmp.begin(), tmp.end(), std::rand);

	Span	test(tmp.size());

	try {
		test.addNumber(tmp.begin(), tmp.end());
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << test << std::endl;
	std::cout << COLOR("The shortest span is ", CYAN) << COLOR(test.shortestSpan(), CYANULINE) << COLOR(".", CYAN) << std::endl;
	std::cout << COLOR("The longest span is ", YELLOW) << COLOR(test.longestSpan(), YELLOWULINE) << COLOR(".", YELLOW) << std::endl;
}

void	longestTest(void) {

	std::cout << COLOR("Span longestSpan() test: ", YELLOW) << std::endl;

	std::deque<int>	tmp(10);
	std::srand(time(NULL));
	std::generate(tmp.begin(), tmp.end(), std::rand);

	Span	test(tmp.size());

	try {
		test.addNumber(tmp.begin(), tmp.end());

		std::cout << test << std::endl;

		std::cout << COLOR("The longest span is ", YELLOW) << COLOR(test.longestSpan(), YELLOWULINE) << COLOR(".", YELLOW) << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
}

void	shortestTest(void) {

	std::cout << COLOR("Span shortestSpan() test: ", CYAN) << std::endl;

	std::deque<int>	tmp(10);
	std::srand(time(NULL));
	std::generate(tmp.begin(), tmp.end(), std::rand);

	Span	test(tmp.size());

	try {
		test.addNumber(tmp.begin(), tmp.end());

		std::cout << test << std::endl;

		std::cout << COLOR("The shortest span is ", CYAN) << COLOR(test.shortestSpan(), CYANULINE) << COLOR(".", CYAN) << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
}

void	exceptionTest(void) {

	std::cout << COLOR("Span adding an element while already full test: ", GREEN) << std::endl;

	try {
		Span	test(5);

		test.addNumber(0);
		test.addNumber(1);
		test.addNumber(2);
		test.addNumber(3);
		test.addNumber(4);

		test.addNumber(5);

		std::cout << test << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << COLOR("Span calling shortest/longest with no element test: ", GREEN) << std::endl;

	try {
		Span	test(5);

		test.longestSpan();
		// test.shortestSpan();
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << COLOR("Span calling shortest/longest with one element added test: ", GREEN) << std::endl;

	try {
		Span	test(5);

		test.addNumber(1);

		test.longestSpan();
		// test.shortestSpan();
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
}

/*
int	main(void) {

	std::cout << std::endl;

	hugeAmountAnnoying();
	std::cout << std::endl << COLOR(std::string(130, '='), WHITEBACK) << std::endl << std::endl;
	hugeAmountOpti();

	// longestTest();
	// std::cout << COLOR(std::string(130, '='), WHITEBACK) << std::endl << std::endl;
	// shortestTest();

	std::cout << std::endl;

	// exceptionTest();

	std::cout << std::endl;

	return (0);
}
*/


//main given in subject
int main() {

	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
}
