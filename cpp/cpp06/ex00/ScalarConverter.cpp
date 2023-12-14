/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:18:26 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/14 17:28:22 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

/*
	Since ScalarConverter needs to be non-instanciable,
	all its canonical functions are in private,
	with no message in them since we can nothing with the class apart from
	calling the static member function convert.
*/
ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	(void)src;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& rhs)
{
	(void)rhs;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
}

/* ************************************************************************** */
/*                             EXTERNAL FUNCTIONS                             */
/*                                  CHECKERS                                  */
/* ************************************************************************** */

bool	validInput(const std::string& strToConvert)
{
	int	nbSign = 0;
	int	posSign = 0;
	int	nbdot = 0;

	for (int i = 0; i < static_cast<int>(strToConvert.length()); i++)
	{
		char	c = strToConvert[i];
		if (c == '-' || c == '+')
		{
			nbSign++;
			posSign = i;
		}
		if (posSign != 0 || nbSign > 1)
			return (false);
		if (c == '.')
		{
			nbdot++;
			if (nbdot > 1)
				return (false);
		}
	}
	return (true);
}

bool	isPseudoLiteral(const std::string& strToConvert)
{
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
	1st if:
	2nd if: if true, then they are multiple characters
	2nd else if: if true, then a single printable characters but with more than 1
	3rd if: Check to have only printable characters
*/
bool	isChar(const std::string& strToConvert)
{
	bool	digit = false;
	bool	cara = false;

	for (size_t i = 0; i < strToConvert.length(); i++)
	{
		if (isdigit(strToConvert[i]))
			digit = true;
		else if (isprint(strToConvert[i]))
			cara = true;
		if (digit && cara)
			return (false);
		else if (cara && !digit && strToConvert.length() > 1)
			return (false);
	}

	int	i = static_cast<int>(atoi(strToConvert.c_str()));
	if (i >= 0 && i <= 127)
		return (true);
	return (false);
}

/*
	Create a stream with strToConvert as content
	I direct it to an int and check if the assignation failed using the functions available
	good() -> globally check if it didn't raise an error
	eof() -> is set to true if all the bytes were assigned, thus reaching the end of stream
*/
bool	isInt(const std::string& strToConvert)
{
	int					n;
	std::istringstream	tmp(strToConvert);

	tmp >> n;
	// if (!tmp.fail() && !tmp.eof())
	// 	return (false);
	// return (true);
	return (!tmp.fail() && tmp.eof());
}

/*
	for: Check if there is more than one 'f' in the input if there is one it must be at the end

	1st if: if there is a 'f' it will remove it
*/
bool	isFloat(const std::string& strToConvert)
{
	std::istringstream	tmp(strToConvert);
	float				f;
	int					nbF = 0;

	for (size_t i = 0; i < strToConvert.length(); i++)
	{
		if (strToConvert[i] == 'f')
			nbF++;
		if (nbF > 1 || (nbF == 1 && i != strToConvert.length() - 1))
			return (false);
	}

	if (strToConvert[strToConvert.length() - 1] == 'f')
	{
		std::string s = strToConvert.substr(0, strToConvert.length() - 1);
		tmp.str(s);
	}

	tmp >> f;
	if (tmp.eof() && !tmp.fail())
		return (true);
	return (false);
	// return (tmp.eof() && !tmp.fail());
}

/*
	same method as for the int
	need to see if the other method is working
*/
bool	isDouble(const std::string& strToConvert)
{
	double				d;
	std::istringstream	tmp(strToConvert);

	// tmp >> d;
	// if (!tmp.fail() && !tmp.eof())
	// 	return (false);
	// return (true);
	if (tmp >> d)
		return (true);
	return (false);
}

/* ************************************************************************** */
/*                             EXTERNAL FUNCTIONS                             */
/*                                  PRINTERS                                  */
/* ************************************************************************** */

/*
	No printLiterarls since already done in the convert function for them
*/

/*
	1st if: Check if a 'f' at the end of input and removes it if there is one
	2nd if: If there is a dot in the input (find returned a value != npos)
		I change dot to indicate that there is one, else there is no dot
*/
void	printChar(const std::string& strToConvert)
{
	double		d = static_cast<double>(atof(strToConvert.c_str()));

	std::string	s;
	if (strToConvert[strToConvert.length() - 1] == 'f')
		s = strToConvert.substr(0, strToConvert.length() - 1);

	int			dot = 0;
	if (strToConvert.find('.') != strToConvert.npos)
		dot = 1;

	if ((isChar(s) && d <= CHAR_MAX && d >= CHAR_MIN) || \
		(!isChar(s) && dot && (d <= CHAR_MAX && d >= CHAR_MIN)))
	{
		char	c = static_cast<char>(d);
		if (isprint(d))
			std::cout << COLOR("char:", UGREEN) << " " << COLOR(c, GREEN) << std::endl;
		else
			std::cout << COLOR("char:", UGREEN) << " " << COLOR(" Non displayable", RED) << std::endl;
	}
	else
		std::cout << COLOR("char:", UGREEN) << COLOR(" impossible", RED) << std::endl;
}

/*
	if the value is within the INT range, then print it
	else print an error
*/
void	printInt(const std::string& strToConvert)
{
	double	d = static_cast<double>(atof(strToConvert.c_str()));
	int		i = static_cast<int>(d);

	if (d <= INT_MAX && d >= INT_MIN)
		std::cout << COLOR("int:", UYELLOW) << " " << COLOR(i, YELLOW) << std::endl;
	else
		std::cout << COLOR("int:", UYELLOW) << COLOR(" impossible", RED) << std::endl;
}

/*
	1st if: If there is a dot in the input (find returned a value != npos)
		I change dot to indicate that there is one, else there is no dot
	2nd if: If there is no dot in the input and the value is within INT range OR
		If there is a dot in the input, that it is at the penultimate position and that the value is within INT range
		then print the value with a precision of 1 (since there is a dot and in range of INT so not too big)
		else print the value as it is (possibly with a lot of fractionnary part)
*/
void	printFloat(const std::string& strToConvert)
{
	int		dot = 0;
	if (strToConvert.find('.') != strToConvert.npos)
		dot = 1;

	float	f = static_cast<float>(atof(strToConvert.c_str()));
	double	d = static_cast<double>(atof(strToConvert.c_str()));

	if ((!dot && (d <= INT_MAX && d >= INT_MIN)) || \
		(dot && strToConvert[strToConvert.length() - 1] == '.' && (d <= INT_MAX && d >= INT_MIN)))
		std::cout << COLOR("float:", UBLUE) << std::fixed << std::setprecision(1) << " " << COLOR(f, BLUE) << COLOR("f", BLUE) << std::endl;
	else
		std::cout << COLOR("float:", UBLUE) << COLOR(f, BLUE) << " " << COLOR("f", BLUE) << std::endl;
}

/*
	1st if: If there is a dot in the input (find returned a value != npos)
		I change dot to indicate that there is one, else there is no dot
	2nd if: If there is no dot in the input and the value is within INT range OR
		If there is a dot in the input, that it is at the penultimate position and that the value is within INT range
		then print the value with a precision of 1 (since there is a dot and in range of INT so not too big)
		else print the value as it is (possibly with a lot of fractionnary part)
*/
void	printDouble(const std::string& strToConvert)
{
	int		dot = 0;
	if (strToConvert.find('.') != strToConvert.npos)
		dot = 1;

	double	d = static_cast<double>(atof(strToConvert.c_str()));

	if ((!dot && (d <= INT_MAX && d >= INT_MIN)) || \
		(dot && strToConvert[strToConvert.length() - 1] == '.' && (d <= INT_MAX && d >= INT_MIN)))
		std::cout << COLOR("double: ", UMAGENTA) << std::fixed << std::setprecision(1) << " " << COLOR(d, MAGENTA) << std::endl;
	else
		std::cout << COLOR("double:", UMAGENTA) << " " << COLOR(d, MAGENTA) << std::endl;
}

/* ************************************************************************** */
/*                             EXTERNAL FUNCTIONS                             */
/*                                 CONVERTERS                                 */
/* ************************************************************************** */

void	convertPseudoLiteral(const std::string& strToConvert)
{
	float	f = static_cast<float>(atof(strToConvert.c_str()));
	double	d = static_cast<double>(atof(strToConvert.c_str()));

	std::cout << COLOR("char:", UGREEN) << COLOR(" impossible", RED) << std::endl;
	std::cout << COLOR("int:", UYELLOW) << COLOR(" impossible", RED) << std::endl;
	std::cout << COLOR("float:", UBLUE) << " " << COLOR(f, BLUE) << COLOR("f", BLUE) << std::endl;
	std::cout << COLOR("double:", UMAGENTA) << " " << COLOR(d, MAGENTA) << std::endl;
}

/*
	1st if: If the first character of the input is a letter and there is one only one character, then I use it directly
		else I cast the whole string (since it will likely be a number).
	2nd if: Check to see if the character is printable, if it is print it else print an error
	3rd if: Check to see if the input is a valid number by calling isFloat(),
		isChar() already checked to see if a number has a character in it.
*/
void	convertChar(const std::string& strToConvert)
{
	char	c;
	if (isalpha(strToConvert[0]) && strToConvert.length() == 1)
		c = strToConvert[0];
	else
		c = static_cast<char>(atoi(strToConvert.c_str()));
	if (isprint(c))
		std::cout << COLOR("char:", UGREEN) << " " << COLOR(c, GREEN) << std::endl;
	else
		std::cout << COLOR("char:", UGREEN) << COLOR(" Non displayable", RED) << std::endl;

	if (isFloat(strToConvert))
	{
		int	i = static_cast<int>(c);
		std::cout << COLOR("int:", UYELLOW) << " " << COLOR(i, YELLOW) << std::endl;
		float	f = static_cast<float>(c);
		std::cout << COLOR("float:", UBLUE) << std::fixed << std::setprecision(1) << " " << COLOR(f, BLUE) << COLOR("f", BLUE) << std::endl;
		double	d = static_cast<double>(c);
		std::cout << COLOR("double:", UMAGENTA) << " " << COLOR(d, MAGENTA) << std::endl;
	}
	else
	{
		std::cout << COLOR("int:", UYELLOW) << COLOR(" impossible", RED) << std::endl;
		std::cout << COLOR("float:", UBLUE) << COLOR(" impossible", RED) << std::endl;
		std::cout << COLOR("double:", UMAGENTA) << COLOR(" impossible", RED) << std::endl;
	}
}

void	convertInt(const std::string& strToConvert)
{
	int	i = static_cast<int>(atoi(strToConvert.c_str()));

	std::cout << COLOR("char:", UGREEN) << COLOR(" impossible", RED) << std::endl;
	std::cout << COLOR("int:", UYELLOW) << " " << COLOR(i, YELLOW) << std::endl;
	// printInt(strToConvert);
	printFloat(strToConvert);
	printDouble(strToConvert);
}

/*
	1st if: If there is a dot in the input (find returned a value != npos)
		I change dot to indicate that there is one, else there is no dot
	2nd if: If there is a dot in the input, I find it's position and obtain the number of digits present after it
	3rd if: If there is no dot in the input and the value is within INT range OR
		If there is a dot in the input, that it is at the penultimate position and that the value is within INT range OR
		If there is only one or none digit after the dot and that the value is within INT range
		then print the value with a precision of 1 (since there is a dot or is in range of INT so not too big,
		or no need to have better precision since only one or less digit after the dot)
		else print the value as it is (possibly with a lot of fractionnary part)
*/
void	convertFloat(const std::string& strToConvert)
{
	int		dotPos = 0, dotDigits = 0, dot = 0;

	if (strToConvert.find('.') != strToConvert.npos)
		dot = 1;

	if (dot == 1)
	{
		dotPos = strToConvert.find('.');
		dotDigits = strToConvert.length() - dotPos - 1;
	}

	printChar(strToConvert);
	printInt(strToConvert);

	float	f = static_cast<float>(atof(strToConvert.c_str()));
	double	d = static_cast<double>(atof(strToConvert.c_str()));

	if ((!dot && (d <= INT_MAX && d >= INT_MIN)) || \
		(dot && strToConvert[strToConvert.length() - 1] == '.' && (d <= INT_MAX && d >= INT_MIN)) || \
		(dotDigits <= 1 && (d <= INT_MAX && d >= INT_MIN)))
	{
		std::cout << COLOR("float:", UBLUE) << std::fixed << std::setprecision(1) << " " << COLOR(f, BLUE) << COLOR("f", BLUE) << std::endl;
		std::cout << COLOR("double:", UMAGENTA) << " " << COLOR(d, MAGENTA) << std::endl;
	}
	else
	{
		std::cout << COLOR("float:", UBLUE) << " " << COLOR(f, BLUE) << COLOR("f", BLUE) << std::endl;
		std::cout << COLOR("double:", UMAGENTA) << " " << COLOR(d, MAGENTA) << std::endl;
	}
}

void	convertDouble(const std::string& strToConvert)
{
	std::cout << COLOR("char:", UGREEN) << COLOR(" impossible", RED) << std::endl;
	std::cout << COLOR("int:", UYELLOW) << COLOR(" impossible", RED) << std::endl;
	std::cout << COLOR("float:", UBLUE) << COLOR(" impossible", RED) << std::endl;
	printDouble(strToConvert);
}

/* ************************************************************************** */
/*                              MEMBERS FUNCTIONS                             */
/* ************************************************************************** */

void	ScalarConverter::convert(const std::string& strToConvert)
{
	if (!validInput(strToConvert))
	{
		std::cout << RED << "Error." << std::endl << "The input is not a valid value. " << RESET << std::endl;
		return ;
	}

	if (isPseudoLiteral(strToConvert))
		convertPseudoLiteral(strToConvert);
	else if (isChar(strToConvert))
		convertChar(strToConvert);
	else if (isInt(strToConvert))
		convertInt(strToConvert);
	else if (isFloat(strToConvert))
		convertFloat(strToConvert);
	else if (isDouble(strToConvert))
		convertDouble(strToConvert);
	else
		std::cout << RED << "Error." << std::endl << "The input is not a valid literal." << RESET << std::endl;
}
