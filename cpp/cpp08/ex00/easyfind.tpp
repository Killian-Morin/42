/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:28:19 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/20 16:22:01 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

/* ************************************************************************** */
/*                             TEMPLATE FUNCTION                              */
/* ************************************************************************** */

template <typename T>
void	easyfind(T& container, int i) {

	try {
		std::find(container.begin(), container.end(), i);
		std::cout << COLOR("The value ", GREEN) << COLOR(i, GREENULINE) << COLOR(" is present in the container", GREEN) << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

/* ************************************************************************** */
/*                              EXCEPTION CLASS                               */
/* ************************************************************************** */

const char*	ParameterNotFoundException::what() const throw() {

	return (RED "Couldn't find the input in the array !" RESET);
}
