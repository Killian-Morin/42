/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:42:21 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 09:53:39 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <string>
#include <iostream>
#include <fstream>

#include "Color.hpp"

//No default constructor since I didn't create a setter for the ≠ attributs
class Replace {

	private:
		std::string	_infile;
		std::string	_outfile;
		std::string	_s1;
		std::string	_s2;

	public:
		//Parametric constructor/Destructor
		Replace(std::string file, std::string s1, std::string s2);
		~Replace(void);

		//Member Function
		void	replace(void);

};

#endif // REPLACE_HPP
