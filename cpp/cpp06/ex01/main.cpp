/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:48:51 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/15 14:59:49 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{

	std::cout << std::endl;

	Data *myData = new Data();

	uintptr_t raw = Serializer::serialize(myData);

	Data *ptr = Serializer::deserialize(raw);

	std::cout << "Raw data: " << raw << std::endl;

	std::cout << "Deserialized data: " << ptr->_n << std::endl;

	delete myData;

	std::cout << std::endl;

	return (0);
}
