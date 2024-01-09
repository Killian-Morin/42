/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:48:51 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:59:01 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

void	printData(Data* data) {

	std::cout << YELLOW << "Value of data structure: _n = " << data->_n << RESET << std::endl;
}

int	main(void) {

	std::cout << std::endl;

	Data data;
	data._n = 42;

	printData(&data);

	// Serialize data structure
	uintptr_t raw = Serializer::serialize(&data);

	// Deserialize data structure
	Data *data2 = Serializer::deserialize(raw);
	printData(data2);

	std::cout << std::endl;

	if (data2 == &data)
		std::cout << GREEN << "The values of the two structures are the same !" << RESET << std::endl;
	else
		std::cout << RED << "The values of the two structure are different ☹️" << RESET << std::endl;

	std::cout << std::endl;

	return (0);
}
