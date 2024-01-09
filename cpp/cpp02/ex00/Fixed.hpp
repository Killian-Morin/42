/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:34:43 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 14:01:06 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

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

#define REDULINE "\e[4;31m"
#define GREENULINE "\e[4;32m"

#define COLOR(text, color) color << text << RESET

class	Fixed {

	private:
		int					_fixedPointValue;
		static const int	_fractionalBits;

	public:
		//Canonical class functions
		Fixed(void);
		Fixed(const Fixed& src);
		Fixed&	operator=(const Fixed& rhs);
		~Fixed(void);

		//Getter/Setter
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif //FIXED_HPP
