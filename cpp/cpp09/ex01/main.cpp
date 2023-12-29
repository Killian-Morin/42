/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:53:54 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/29 11:21:46 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av) {

	if (ac != 2) {
		std::cout << COLOR("Usage: ./RPN \" ... \"", RED) << std::endl;
		return (1);
	}

	RPN	a;

	if (!a.checker(av[1]))
		return (1);

	a.run(av[1]);

	return (0);
}
