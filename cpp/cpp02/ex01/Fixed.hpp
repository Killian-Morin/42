/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:46:03 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 14:01:10 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

#ifndef SHOWMSG
# define SHOWMSG 0
#endif //SHOWMSG

#define RESET "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CYAN "\e[0;36m"
#define WHITE "\e[0;37m"

#define BOLDGREEN "\e[1;32m"

#define COLOR(text, color) color << text << RESET

class	Fixed {

	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;

	public:
		//Canonical class functions
		Fixed(void);
		Fixed(const Fixed& src);
		Fixed&	operator=(const Fixed& rhs);
		~Fixed(void);

		//Getter/Setter
		int		getRawBits(void) const;
		void	setRawBits(const int raw);

		//Parametric Constructors
		Fixed(const int n);
		Fixed(const float n);

		//Member Functions
		int		toInt(void) const;
		float	toFloat(void) const;
};

//Operator overload to print Fixed class info
std::ostream&	operator<<(std::ostream& o, Fixed const& instance);

#endif //FIXED_HPP
