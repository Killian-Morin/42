/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:54:48 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 10:04:26 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int	main(int ac, char **av) {

	if (ac != 4) {
		std::cout << COLOR("Sorry, not the right amount of parameters: needs 3", RED) << std::endl;
		return (1);
	}

	Replace	sed(av[1], av[2], av[3]);

	sed.replace();

	std::cout << std::endl;

	return (0);
}
