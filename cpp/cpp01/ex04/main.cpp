/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:54:48 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/22 14:19:43 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << RED << "Sorry, not the right amount of parameters: needs 3" << WHITE << std::endl;
		return (1);
	}

	Replace	sed(av[1], av[2], av[3]);
	sed.replace();

	return (0);
}
