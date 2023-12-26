/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:28:18 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/26 15:51:57 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

static int	array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
static int	N = sizeof(array) / sizeof(int);

void	deque(int input) {

	std::deque<int>	d;

	std::cout << COLOR("easyfind with a ", YELLOW) << COLOR("deque", YELLOWULINE) << COLOR(" container.", YELLOW) << std::endl;

	for (int i = 0; i < N; i++)
		d.push_back(array[i]);

	try {
		easyfind(d, input);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
}

void	vector(int input) {

	std::vector<int>	v;

	std::cout << COLOR("easyfind with a ", MAGENTA) << COLOR("vector", MAGENTAULINE) << COLOR(" container.", MAGENTA) << std::endl;

	for (int i = 0; i < N; i++)
		v.push_back(array[i]);

	try {
		easyfind(v, input);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	list(int input) {

	std::list<int>	l;

	std::cout << COLOR("easyfind with a ", CYAN) << COLOR("list", CYANULINE) << COLOR(" container.", CYAN) << std::endl;

	for (int i = 0; i < N; i++)
		l.push_back(array[i]);

	try {
		easyfind(l, input);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
}

void	handleCtrlD(void)
{
	if (std::cin.eof()) {

		std::cout << std::endl << COLOR("Exit easyfind (with ^D).", RED) << std::endl;
		exit (0);
	}
}

int	main(void) {

	std::cout << std::endl;

	std::string	input;
	while (1) {
		
		std::cout << COLOR("The container has the following values: ", BLUE);
		for (int i = 0; i < N; i++) {
			std::cout << COLOR(array[i], BLUEULINE);
			if (i < 9)
				std::cout << ", ";
			else
				std::cout << "." << std::endl;
		}
		std::cout << std::endl;

		std::cout << COLOR("Enter an integer", BLUE)  << std::endl << "> ";
		std::cin >> input;
		handleCtrlD();
		std::cout << std::endl;

		if (input == "exit") {
			std::cin.clear();
			std::cout << RED << "Exit easyfind." << std::endl << "Bye !" << RESET << std::endl;
			break ;
		}

		std::cout << COLOR(std::string(60, '='), WHITE) << std::endl << std::endl;

		deque(std::atoi(input.c_str()));

		std::cout << COLOR(std::string(60, '='), WHITE) << std::endl << std::endl;

		vector(std::atoi(input.c_str()));

		std::cout << COLOR(std::string(60, '='), WHITE) << std::endl << std::endl;

		list(std::atoi(input.c_str()));

	}

	return (0);
}
