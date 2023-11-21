/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:42:21 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/21 14:47:39 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

#define RED "\033[31m"
#define GREEN "\e[0;32m"
#define BLUE "\e[0;34m"
#define WHITE "\033[37m"

class Replace
{
	public:
		Replace(std::string file, std::string s1, std::string s2);
		~Replace();

		void	replace(void);

	private:
		std::string	_infile;
		std::string	_outfile;
		std::string	_s1;
		std::string	_s2;
};