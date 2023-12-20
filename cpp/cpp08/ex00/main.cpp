/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:28:18 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/20 16:28:35 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void	handleCtrlD(void)
{
	if (std::cin.eof()) {

		std::cout << std::endl << COLOR("Exit easyfind (with ^D).", RED) << std::endl;
		exit (0);
	}
}

void	deque(int input, int array[50]) {

	// std::cout << COLOR("Assignation of the values of the int array to the ", YELLOW) << \
		// COLOR("deque", YELLOWULINE) << COLOR(" container.", YELLOW) << std::endl << std::endl;

	std::deque<int>	dequeInt;

	for (int i = 0; i < 50; i++)
		dequeInt.push_back(array[i]);

	std::cout << COLOR("Call easyfind to check if the input is present in the array of int", YELLOW) << std::endl;
	easyfind(dequeInt, input);
	std::cout << std::endl;
}

void	vector(int input, int array[50]) {

	// std::cout << COLOR("Assignation of the values of the int array to the ", MAGENTA) << \
		// COLOR("vector", MAGENTAULINE) << COLOR(" container.", MAGENTA) << std::endl << std::endl;

	std::vector<int>	vectorInt;

	for (int i = 0; i < 50; i++)
		vectorInt.push_back(array[i]);

	std::cout << COLOR("Call easyfind to check if the input is present in the array of int", MAGENTA) << std::endl;
	easyfind(vectorInt, input);
	std::cout << std::endl;
}

void	list(int input, int array[50]) {

	// std::cout << COLOR("Assignation of the values of the int array to the ", CYAN) << \
		// COLOR("vector", CYANULINE) << COLOR(" container.", CYAN) << std::endl << std::endl;

	std::list<int>	listInt;

	for (int i = 0; i < 50; i++)
		listInt.push_back(array[i]);

	std::cout << COLOR("Call easyfind to check if the input is present in the array of int", CYAN) << std::endl;
	easyfind(listInt, input);
	std::cout << std::endl;
}

int	main(void) {

	std::cout << std::endl;

	std::string	input;
	while (1) {

		std::cout << COLOR("Enter an integer", BLUE)  << std::endl << "> ";
		std::cin >> input;
		handleCtrlD();
		std::cout << std::endl;

		if (input == "exit") {
			std::cin.clear();
			std::cout << RED << "Exit easyfind." << std::endl << "Bye !" << RESET << std::endl;
			break ;
		}

		int	inputInt = atoi(input.c_str());
		if (inputInt >= INT_MAX || inputInt <= INT_MIN) {
			std::cin.clear();
			std::cout << "The input is not a valid integer (not in range) ! Try again." << std::endl;
		}
		else
		{
			std::cin.clear();
			std::cout << COLOR("Enter the type of container that you want to use [deque, vector or list]", BLUE) << std::endl << "> ";
			std::cin >> input;
			handleCtrlD();
			std::cout << std::endl;

			if (input == "exit") {
				std::cin.clear();
				std::cout << RED << "Exit easyfind." << std::endl << "Bye !" << RESET << std::endl;
				break ;
			}
			else if (input != "deque" && input != "vector" && input != "list") {
				std::cout << COLOR("Invalid container type ! Try again.", RED) << std::endl;
				std::cin.clear();
			}

			std::cout << COLOR("Creation of an array of 10 int with random values.", BLUE) << std::endl;
			int	array[10];
			srand(time(NULL));
			for (int i = 0; i < 10; i++)
				array[i] = rand();
			for (int i = 0; i < 10; i++) {
				std::cout << array[i];
				if (i < 9)
					std::cout << ", ";
				else
					std::cout << "." << std::endl << std::endl;
			}

			if (input == "deque") {
				deque(inputInt, array);
				std::cin.clear();
				std::cin.ignore();
			}
			else if (input == "vector") {
				vector(inputInt, array);
				std::cin.clear();
				std::cin.ignore();
			}
			else if (input == "list") {
				list(inputInt, array);
				std::cin.clear();
				std::cin.ignore();
			}
		}
		std::cout << COLOR(std::string(60, '='), RED) << std::endl;

		handleCtrlD();

	}
	return (0);
}
