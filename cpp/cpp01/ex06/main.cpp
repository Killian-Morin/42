/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:08:21 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/22 11:37:01 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl		harl;
	std::string	input;

	while (1)
	{
		std::cout << "Enter a level of complaint > ";
		std::cin >> input;

		harl.exitHandler(input);

		harl.complain(input);

		std::cin.clear();
		std::cin.ignore();
	}

	return (0);
}
