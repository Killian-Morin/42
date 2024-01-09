/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:54:10 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 16:04:27 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void) {

	std::cout << std::endl;

	std::cout << YELLOW << "Creation of an array with no len specified" << std::endl;
	Array<int>	empty;
	std::cout << "\tsize of Array<int> empty : " << empty.size() << RESET << std::endl;

	std::cout << std::endl;

	std::cout << MAGENTA << "Creation of an array with a len of 2" << std::endl;
	Array<char>	tmp(2);
	std::cout << "\tsize of Array<char> tmp : " << tmp.size() << RESET << std::endl;

	std::cout << MAGENTA << "To which we assign some values:\n";
	tmp[0] = 74;
	tmp[1] = 42;
	std::cout << "\ttmp[0]: " << tmp[0] << "\n\ttmp[1]: " << tmp[1] << std::endl;

	std::cout << std::endl;

	std::cout << YELLOW << "Assignation operator check\t" << std::endl;
	Array<char>	other;
	other = tmp;
	std::cout << "\tsize of Array<char> other : " << other.size() << std::endl;
	std::cout << "\tother[0]: " << other[0] << std::endl;
	std::cout << "\tother[1]: " << other[1] << std::endl;

	std::cout << std::endl;

	std::cout << CYAN << "Copy constructor check:" << std::endl;
	Array<char>	tmp2(tmp);
	std::cout << "\tsize of Array<char> tmp2 : " << tmp2.size() << std::endl;
	std::cout << "Changing the value of tmp2[1]" << std::endl;
	tmp2[1] = 43;
	std::cout << "\ttmp[1]: " << tmp[1] << std::endl;
	std::cout << "\ttmp2[1]: " << tmp2[1] << std::endl;

	std::cout << std::endl;

	std::cout << MAGENTA << "Creation of an Array of type double with a len of 5 " << \
		"and accessing each of them with the [] operator\n\t";
	Array<double>	test(5);
	for (int i = 0; i < 5; i++) {
		std::cout << test[i];
		if (i < 4)
			std::cout << ", ";
		else
			std::cout << "." << std::endl;
	}

	std::cout << std::endl;

	try {
		std::cout << CYAN << "Creation of an Array of type std::string with a len of 5 and accessing out of bounds index\n\t";
		Array<std::string>	bob(5);
		std::cout << bob[5] << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	return (0);
}

/*
	//main given

#define MAX_VAL 750

int main(int, char**)
{
	Array<int>	numbers(MAX_VAL);//Creation of an Array of int

	int* mirror = new int[MAX_VAL];//creation of a normal array of int

	srand(time(NULL));

	//assign the same values for the normal array and the one created from the Class template
	for (int i = 0; i < MAX_VAL; i++) {
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	//Test deep copy for assignation operator and copy constructor
	{
		Array<int>	tmp = numbers;
		Array<int>	test(tmp);
	}

	//compare the values that were assigned | not supposed to have an error message
	for (int i = 0; i < MAX_VAL; i++) {
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}

	//check the exception for an index out of the scope of the Array
	try {
		numbers[-2] = 0;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	//check the exception for an index out of the scope of the Array
	try {
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	//reassign the values | not supposed to cause a problem
	for (int i = 0; i < MAX_VAL; i++)
		numbers[i] = rand();

	//do not delete the Array created from the Class template since it will be delete in the destructor
	delete [] mirror;

	return 0;
}*/
