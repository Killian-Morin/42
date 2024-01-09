/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:42:10 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 10:36:26 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

/* ************************************************************************** */
/*                      PARAMETRIC CONSTRUCTOR/DESTRUCTOR                     */
/* ************************************************************************** */

Replace::Replace(std::string file, std::string s1, std::string s2) : _infile(file), _s1(s1), _s2(s2) {

	this->_outfile = _infile + ".replace";

	if (SHOWMSG)
		std::cout << COLOR("Replace", GREENULINE) << COLOR(" Parametric constructor called", GREEN) << std::endl;
}

Replace::~Replace(void) {

	if (SHOWMSG)
		std::cout << COLOR("Replace", REDULINE) << COLOR(" Default destructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                               MEMBER FUNCTION                              */
/* ************************************************************************** */

void	Replace::replace(void) {

	//TO OPEN THE INFILE
	std::ifstream	infile;

	infile.open(this->_infile, std::ifstream::in);
	if (!infile.good()) {
		std::cout << COLOR("Sorry, the infile couldn't be open.", RED) << std::endl;
		exit(1);
	}
	std::cout << COLOR(this->_infile, GREENULINE) << " is open." << std::endl << std::endl;


	//TO OPEN/CREATE THE OUTFILE
	std::ofstream	outfile;

	outfile.open(this->_outfile, std::ofstream::out | std::ofstream::trunc);
	if (!outfile.good()) {
		std::cout << COLOR("Sorry, the outfile couldn't be open.", RED) << std::endl;
		exit(1);
	}
	std::cout << COLOR(this->_outfile, GREENULINE) << " is open." << std::endl << std::endl;

	//LOOP THAT COPIES THE CONTENT OF INFILE TO OUTFILE WHILE REPLACING EACH OCCURRENCE OF S1 BY S2
	std::string	line;
	while (getline(infile, line)) {

		if (line.compare(this->_s1) == 0) {
			line.erase(0, line.npos);
			line.insert(0, this->_s2);
		}
		outfile << line;
		if (line.find("\n", 0) == line.npos)
			outfile << "\n";
	}

	infile.close();
	outfile.close();

	std::cout << COLOR("All contents of ", BLUE) << COLOR(this->_infile, BLUEULINE) << \
		COLOR(" has been copied to ", BLUE) << COLOR(this->_outfile, BLUEULINE) << \
		COLOR(" and each occurrence of ", BLUE) << COLOR(this->_s1, BLUEULINE) << \
		COLOR(" has been replaced by ", BLUE) << COLOR(this->_s2, BLUEULINE) << std::endl;
}
