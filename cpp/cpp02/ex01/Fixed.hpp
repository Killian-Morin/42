/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:46:03 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/27 15:47:55 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

#define RED "\e[31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CYAN "\e[0;36m"
#define WHITE "\e[37m"

class	Fixed {
	public:
		Fixed();
		~Fixed();

		Fixed(const Fixed& other);//copy constructor
		Fixed& operator=(const Fixed& rhs);//assignment operator overload

		int		getRawBits(void) const;
		void	setRawBits(const int raw);

		Fixed(const int n);//constructor for integers
		Fixed(const float n);//constructor for floats¡

		int		toInt(void) const;
		float	toFloat(void) const;

	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
};

std::ostream&	operator<<(std::ostream& o, Fixed const& instance);

#endif
