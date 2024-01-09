/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:53:27 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 16:03:25 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

#define RESET "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CYAN "\e[0;36m"
#define WHITE "\e[0;37m"

template <typename T>
void	iter(T* array, int len, void (*f)(T const&)) {

	for (int i = 0; i < len; i++)
		f(array[i]);
}

template <typename T, typename TFunc>
void	iter(T* array, int len, TFunc f) {

	for (int i = 0; i < len; i++)
		f(array[i]);
}

template <typename T>
void	print(T const& x) {

	std::cout << "\t" << x << std::endl;
}

#endif //ITER_HPP
