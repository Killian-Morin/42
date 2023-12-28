/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:58:24 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/28 15:01:39 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av) {

	if (ac != 2) {
		std::cout << COLOR("Usage: ./btc filename", RED) << std::endl;
		return (1);
	}

	BitcoinExchange	a("data.csv");

	a.run(av[1]);

	return (0);
}
