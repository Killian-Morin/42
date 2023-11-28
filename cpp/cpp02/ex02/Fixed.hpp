/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 08:37:12 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/28 13:01:39 by kmorin           ###   ########.fr       */
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
		Fixed(const float n);//constructor for floats

		int		toInt(void) const;
		float	toFloat(void) const;

		bool	operator>(const Fixed& rhs) const;//greater than
		bool	operator<(const Fixed& rhs) const;//smaller than
		bool	operator>=(const Fixed& rhs) const;//greater or equal than
		bool	operator<=(const Fixed& rhs) const;//smaller or equal than
		bool	operator==(const Fixed& rhs) const;//equal
		bool	operator!=(const Fixed& rhs) const;//different than

		Fixed	operator+(const Fixed& rhs) const;//addition
		Fixed	operator-(const Fixed& rhs) const;//substraction
		Fixed	operator*(const Fixed& rhs) const;//multiplication
		Fixed	operator/(const Fixed& rhs) const;//division

		Fixed&	operator++(void);//pre incrementation
		Fixed	operator++(int);//post incrementation
		Fixed&	operator--(void);//pre decrementation
		Fixed	operator--(int);//post decrementation

		static Fixed&		min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);

		static Fixed&		max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);

	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
};

std::ostream&	operator<<(std::ostream& o, Fixed const& instance);

#endif
