/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:04:46 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/15 15:14:45 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BASE_HPP
#define BASE_HPP

#include <iomanip>
#include <string>

#include "Color.hpp"

#ifndef SHOWMSG
# define SHOWMSG 0
#endif

class Base {

	public:
		virtual ~Base(void);

};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif
