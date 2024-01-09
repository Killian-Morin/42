/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:18:26 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:57:26 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

/*
	Since ScalarConverter has to be non-instanciable,
	all its canonical functions are in private,
	with no message in them since we can nothing with the class apart from
	calling the static member function convert.
*/
ScalarConverter::ScalarConverter(void) {

	if (SHOWMSG)
		std::cout << COLOR("ScalaraConverter ", BLUE) << COLOR("Default constructor called", GREEN) << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& src) {

	*this = src;
	if (SHOWMSG)
		std::cout << COLOR("ScalaraConverter ", BLUE) << COLOR("Copy constructor called", GREEN) << std::endl;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& rhs) {

	(void)rhs;
	if (SHOWMSG)
		std::cout << COLOR("ScalaraConverter ", BLUE) << COLOR("Assignation operator called", GREEN) << std::endl;
	return (*this);
}

ScalarConverter::~ScalarConverter(void) {

	if (SHOWMSG)
		std::cout << COLOR("ScalaraConverter ", BLUE) << COLOR("Default destructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                             EXTERNAL FUNCTIONS                             */
/*                                  PRINTERS                                  */
/* ************************************************************************** */

/*
	No printLiterarls since already done in the convert function for them
*/

void	printChar(char c, bool isPossible) {

	if (!isPossible)
		std::cout << COLOR("char:", UGREEN) << COLOR(" impossible", RED) << std::endl;
	else if (isprint(c))
		std::cout << COLOR("char:", UGREEN) << GREEN << " '" << c << "'" << RESET << std::endl;
	else
		std::cout << COLOR("char:", UGREEN) << " " << COLOR(" Non displayable", RED) << std::endl;
}

void	printInt(int i, bool isPossible) {

	if (!isPossible)
		std::cout << COLOR("int:", UYELLOW) << COLOR(" impossible", RED) << std::endl;
	else
		std::cout << COLOR("int:", UYELLOW) << " " << COLOR(i, YELLOW) << std::endl;
}

void	printFloat(float f, bool isPossible) {

	if (!isPossible)
		std::cout << COLOR("float:", UBLUE) << COLOR(" impossible", RED) << std::endl;
	else
		std::cout << COLOR("float:", UBLUE) << " " << BLUE << std::fixed << std::setprecision(1) << f << "f" << RESET << std::endl;
}

void	printDouble(double d, bool isPossible) {

	if (!isPossible)
		std::cout << COLOR("double:", UMAGENTA) << COLOR(" impossible", RED) << std::endl;
	else
		std::cout << COLOR("double:", UMAGENTA) << " " << MAGENTA << std::fixed << std::setprecision(1) << d << RESET << std::endl;
}

/* ************************************************************************** */
/*                             EXTERNAL FUNCTIONS                             */
/*                                 CONVERTERS                                 */
/* ************************************************************************** */

void	convertPseudoLiteral(const std::string& strToConvert) {

	printChar(0, false);
	printInt(0, false);
	float	f = static_cast<float>(atof(strToConvert.c_str()));
	std::cout << COLOR("float:", UBLUE) << " " << COLOR(f, BLUE) << COLOR("f", BLUE) << std::endl;
	double	d = static_cast<double>(atof(strToConvert.c_str()));
	std::cout << COLOR("double:", UMAGENTA) << " " << COLOR(d, MAGENTA) << std::endl;
}

void	convertChar(const std::string& strToConvert) {

	char	c = strToConvert[0];
	printChar(c, true);

	printInt(static_cast<int>(c), true);

	printFloat(static_cast<float>(c), true);

	printDouble(static_cast<double>(c), true);
}

/*
	a stream read from the new input
	we try to write to a int
	char: print with a cast
	int: depending on the result of the write,
		print an error or with a cast
	float: print with a cast
	double: print with a cast
	clear stream
*/
void	convertInt(const std::string& strToConvert) {

	std::stringstream	streamInt;
	int					i;

	streamInt << strToConvert;
	streamInt >> i;

	printChar(static_cast<char>(i), true);

	if (streamInt.fail())
		printInt(0, false);
	else
		printInt(i, true);

	printFloat(static_cast<float>(i), true);
	printDouble(static_cast<double>(i), true);

	streamInt.clear();
}

/*
	create a new string that remove the 'f' at the last position
	both streams read from the new string
	we try to write to a float or an int from the new string
	char: print with a cast
	int: depending on the result of the write,
		print an error or with a cast
	float: depending on the result of the write,
		print an error or with a cast
	double: print with a cast
	clear both streams
*/
void	convertFloat(const std::string& strToConvert) {

	std::stringstream	streamFloat;
	std::stringstream	streamInt;
	std::string			s;
	float				f;
	int					i;

	s = strToConvert.substr(0, strToConvert.length() - 1);

	streamFloat << s;
	streamInt << s;

	streamFloat >> f;
	streamInt >> i;

	printChar(static_cast<char>(f), true);

	if (streamInt.fail())
		printInt(0, false);
	else
		printInt(static_cast<int>(i), true);

	if (streamFloat.fail())
		printFloat(0, false);
	else
		printFloat(static_cast<float>(f), true);

	printDouble(static_cast<double>(f), true);

	streamFloat.clear();
	streamInt.clear();
}

/*
	create a new string that remove the 'f' at the last position
	both streams read from the new string
	we try to write to a double or an int from the new string
	print the char with a cast
	print the float with a cast
	depending on the result, print an error or print with a cast to the result
	clear both streams
*/
void	convertDouble(const std::string& strToConvert) {

	std::stringstream	streamDouble;
	std::stringstream	streamInt;
	std::string			s;
	double				d;
	int					i;

	s = strToConvert.substr(0, strToConvert.length() - 1);

	streamDouble << s;
	streamInt << s;

	streamDouble >> d;
	streamInt >> i;

	printChar(static_cast<char>(d), true);

	if (streamInt.fail())
		printInt(0, false);
	else
		printInt(static_cast<int>(d), true);

	printFloat(static_cast<float>(d), true);

	if (streamDouble.fail())
		printDouble(0, false);
	else
		printDouble(static_cast<double>(d), true);

	streamDouble.clear();
	streamInt.clear();
}

/* ************************************************************************** */
/*                             EXTERNAL FUNCTIONS                             */
/*                                  CHECKERS                                  */
/* ************************************************************************** */

bool	isPseudoLiteral(const std::string& strToConvert) {

	if (strToConvert == "-inff" || \
		strToConvert == "+inff" || \
		strToConvert == "inff" || \
		strToConvert == "nanf" || \
		strToConvert == "-inf" || \
		strToConvert == "+inf" || \
		strToConvert == "inf" || \
		strToConvert == "nan")
	{
		return (true);
	}
	return (false);
}

/*
	Check if the input is empty
	Check if the input is a single character or a pseudo literal
	Check if the input is a string, that is has only valid character (digits, f, -, + and .)
	Check for the number of sign, dot and 'f' in the input
		return false if > 1
*/
bool	validInput(const std::string& strToConvert) {

	int	nbSign = 0;
	int	posSign = 0;
	int	nbDot = 0;
	int	nbF = 0;

	if (strToConvert.empty())
		return (false);

	if (strToConvert.length() == 1 || isPseudoLiteral(strToConvert))
		return (true);

	if (strToConvert.length() > 1) {
		for (size_t i = 0; i < strToConvert.length(); i++) {
			if (!isdigit(strToConvert[i]) && strToConvert[i] != 'f' && strToConvert[i] != '-' && strToConvert[i] != '+' && strToConvert[i] != '.')
				return (false);
		}
	}

	for (size_t i = 0; i < strToConvert.length(); i++) {
		if (strToConvert[i] == '-' || strToConvert[i] == '+') {
			nbSign++;
			posSign = i;
		}

		if (strToConvert[i] == '.')
			nbDot++;

		if (strToConvert[i] == 'f')
			nbF++;

		if (posSign != 0 || nbSign > 1 || nbDot > 1 || nbF > 1)
			return (false);
	}

	return (true);
}

/*
	if the string contains only one character and that it's not a digit -> return true
	else -> return false
*/
bool	isChar(const std::string& strToConvert) {

	if (strToConvert.length() == 1 && !isdigit(strToConvert[0]))
		return (true);
	return (false);
}

/*
	Check if the last character is a 'f',
		if it is -> return true
		else -> return false
*/
bool	isFloat(const std::string& strToConvert) {

	if (strToConvert.back() != 'f')
		return (false);
	return (true);
}

bool	isDouble(const std::string& strToConvert) {

	if (strToConvert.find('.') != strToConvert.npos)
		return (true);
	return (false);
}

/* ************************************************************************** */
/*                              MEMBER FUNCTIONS                             */
/* ************************************************************************** */

void	ScalarConverter::convert(const std::string& strToConvert) {

	if (!validInput(strToConvert)) {
		std::cout << RED << "Error." << std::endl << "The input is not a valid input. " << RESET << std::endl;
		return ;
	}

	if (isPseudoLiteral(strToConvert))
		convertPseudoLiteral(strToConvert);
	else if (isChar(strToConvert))
		convertChar(strToConvert);
	else if (isFloat(strToConvert))
		convertFloat(strToConvert);
	else if (isDouble(strToConvert))
		convertDouble(strToConvert);
	else
		convertInt(strToConvert);
}
