/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:52:35 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 16:03:07 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WHATEVER_HPP
#define WHATEVER_HPP

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
void	swap(T& x, T& y) {

	T	tmp;

	tmp = x;
	x = y;
	y = tmp;
}

template <typename T>
const T&	min(const T& x, const T& y) {

	return (x < y ? x : y);
}

template <typename T>
const T&	max(const T& x, const T& y) {

	return (x > y ? x : y);
}

#endif //WHATEVER_HPP
