/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:41:16 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/15 15:02:22 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iomanip>
#include <string>

#include "Color.hpp"

#ifndef SHOWMSG
# define SHOWMSG 0
#endif

struct Data {

	int	_n;

};

class Serializer {

	private:
		//Canonical class functions
		Serializer(void);
		Serializer(const Serializer& src);
		Serializer&	operator=(const Serializer& rhs);
		~Serializer(void);

	public:
		//Member functions
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

};

#endif
