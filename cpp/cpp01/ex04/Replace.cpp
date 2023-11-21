/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:42:10 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/21 15:18:31 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string file, std::string s1, std::string s2) : _infile(file), _s1(s1), _s2(s2)
{
	this->_outfile = _infile + ".replace";
}

Replace::~Replace()
{
}

void	Replace::replace(void)
{
	//TO OPEN THE INFILE
	std::ifstream	infile;
	infile.open(this->_infile, std::ifstream::in);
	if (!infile.good())
	{
		std::cout << RED << "Sorry, the infile couldn't be open." << WHITE << std::endl;
		exit(1);
	}
	std::cout << GREEN << this->_infile << " is open." << WHITE << std::endl << std::endl;


	//TO OPEN/CREATE THE OUTFILE
	std::ofstream	outfile;
	outfile.open(this->_outfile, std::ofstream::out | std::ofstream::trunc);
	if (!outfile.good())
	{
		std::cout << RED << "Sorry, the outfile couldn't be open." << WHITE << std::endl;
		exit(1);
	}
	std::cout << GREEN << this->_outfile << " is open." << WHITE << std::endl << std::endl;


	//LOOP THAT COPIES THE CONTENT OF INFILE TO OUTFILE WHILE REPLACING EACH OCCURRENCE OF S1 BY S2
	std::string	line;
	while (getline(infile, line))
	{
		if (line.compare(this->_s1) == 0)
		{
			line.erase(0, line.npos);
			line.insert(0, this->_s2);
		}
		outfile << line;
		if (line.find("\n", 0) == line.npos)
			outfile << "\n";
	}

	infile.close();
	outfile.close();

	std::cout << "All contents of " << BLUE << this->_infile << WHITE;
	std::cout << " has been copied to " << BLUE << this->_outfile << WHITE;
	std::cout << " and each occurrence of " << BLUE << this->_s1 << WHITE;
	std::cout << " has been replaced by " << BLUE<< this->_s2 << WHITE << std::endl;
}
