/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:05:44 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 16:01:07 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main(void) {

	std::cout << std::endl;

	Base*	test = generate();

	identify(test);
	identify(*test);

	delete test;

	std::cout << std::endl;

	return (0);
}
