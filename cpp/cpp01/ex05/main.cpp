/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:31:16 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 10:22:50 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void) {

	Harl		harl;
	std::string	input;

	while (1) {

		std::cout << "Enter a level of complaint [DEBUG, INFO, WARNING, ERROR] > ";
		std::cin >> input;

		if (!harl.exitHandler(input))
			return (1);

		harl.complain(input);

		std::cin.clear();
		std::cin.ignore();
	}

	return (0);
}
