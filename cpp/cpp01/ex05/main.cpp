/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:31:16 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/21 15:58:39 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl		harl;
	std::string	input;

	do
	{
		std::cout << "Enter a level of complaint > ";
		std::cin >> input;

		harl.complain(input);

		std::cin.clear();
		std::cin.ignore();
	} while (!input.compare("exit"));

	return (0);
}
