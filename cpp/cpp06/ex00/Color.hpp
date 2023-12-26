/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Color.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:01:55 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/14 15:19:09 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef COLOR_HPP
#define COLOR_HPP

#include <iostream>

#define RESET "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CYAN "\e[0;36m"
#define WHITE "\e[0;37m"

#define UGREEN "\e[4;32m"
#define UYELLOW "\e[4;33m"
#define UBLUE "\e[4;34m"
#define UMAGENTA "\e[4;35m"

#define COLOR(text, color) color << text << RESET

#endif