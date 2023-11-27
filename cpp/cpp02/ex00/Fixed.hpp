/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:34:43 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/27 11:34:05 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

#define RED "\033[31m"
#define GREEN "\e[0;32m"
#define BLUE "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CYAN "\e[0;36m"
#define WHITE "\033[37m"

class	Fixed {
	public:
		Fixed();
		~Fixed();

		Fixed(const Fixed& other);//copy constructor
		Fixed& operator=(Fixed& rhs);//assignment operator overload

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					_value;
		static const int	_bits;
};

#endif
