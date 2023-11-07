/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:46:05 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/07 15:05:27 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _nbContact(0), _oldestContact(0)
{
	std::cout << "PhoneBook constructor called" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook destructor called" << std::endl;
}

void	PhoneBook::handleCtrlD(void) const
{
	if (std::cin.eof())
	{
		std::cout << std::endl << "Exit the phonebook (with ^D)." << std::endl;
		exit (0);
	}
}

int	PhoneBook::notValidPhoneNumber(std::string input) const
{
	if (input[0] && input[0] == '+')
	{
		if (input.length() < 12)
			return (1);
	}
	else if (input.length() < 10)
		return (1);
	for (int i = 0; input[i]; i++)
	{
		if (i == 0 && input[i] == '+')
			i++;
		if (!std::isdigit(input[i]))
			return (1);
	}
	return (0);
}

void	PhoneBook::add(void)
{
	int	index;

	if (this->_nbContact < 8)
	{
		index = this->_nbContact;
		this->_nbContact++;
	}
	else
	{
		index = this->_oldestContact;
		this->_oldestContact = (this->_oldestContact + 1) % 8;
	}

	std::string	input;
	std::cin.ignore();
	do
	{
		std::cout << "First Name: ";
		std::getline(std::cin, input);
		this->handleCtrlD();
		if (input.empty())
		{
			std::cout << RED << "This can't be null, please try again." << WHITE << std::endl;
			std::cin.clear();
		}
	} while (input.empty());
	this->_contact[index].set_FirstName(input);

	do
	{
		std::cout << "Last Name: ";
		std::getline(std::cin, input);
		this->handleCtrlD();
		if (input.empty())
		{
			std::cout << RED << "This can't be null, please try again." << WHITE << std::endl;
			std::cin.clear();
		}
	} while (input.empty());
	this->_contact[index].set_LastName(input);

	do
	{
		std::cout << "Nickname: ";
		std::getline(std::cin, input);
		this->handleCtrlD();
		if (input.empty())
		{
			std::cout << RED << "This can't be null, please try again." << WHITE << std::endl;
			std::cin.clear();
		}
	} while (input.empty());
	this->_contact[index].set_Nickname(input);

	do
	{
		std::cout << "Phone Number: ";
		std::getline(std::cin, input);
		this->handleCtrlD();
		if (input.empty())
		{
			std::cout << RED << "This can't be null, please try again." << WHITE << std::endl;
			std::cin.clear();
		}
		if (notValidPhoneNumber(input))
		{
			std::cout << RED << "This is not a valid Phone Number, please try again" << WHITE << std::endl;
			std::cin.clear();
		}
	} while (input.empty() || notValidPhoneNumber(input));
	this->_contact[index].set_PhoneNumber(input);

	do
	{
		std::cout << "Darkest Secret: ";
		std::getline(std::cin, input);
		this->handleCtrlD();
		if (input.empty())
		{
			std::cout << RED << "This can't be null, please try again." << WHITE << std::endl;
			std::cin.clear();
		}
	} while (input.empty());
	this->_contact[index].set_Secret(input);
}

void	PhoneBook::search(void) const
{
	std::cout << MAGENTA << "All contacts of the phonebook: " << std::endl;
	std::string	line(43, '-');
	std::cout << "/" << line << "\\" << std::endl;
	std::cout << "|" << std::setw(10) << "INDEX";
	std::cout << "|" << std::setw(10) << "FIRST NAME";
	std::cout << "|" << std::setw(10) << "LAST NAME";
	std::cout << "|" << std::setw(10) << "NICKNAME" << "|" << std::endl;

	for (int i = 0; i < this->_nbContact; i++)
	{
		std::cout << "|" << std::setw(10) << i + 1;
		std::string	value;
		value = this->_contact[i].get_FirstName();
		if (value.size() >= 10)
		{
			value.erase(9, value.npos);
			value.replace(9, 1, 1, '.');
		}
		std::cout << "|" << std::setw(10) << value;
		value = this->_contact[i].get_LastName();
		if (value.size() >= 10)
		{
			value.erase(9, value.npos);
			value.replace(9, 1, 1, '.');
		}
		std::cout << "|" << std::setw(10) << value;
		value = this->_contact[i].get_Nickname();
		if (value.size() >= 10)
		{
			value.erase(9, value.npos);
			value.replace(9, 1, 1, '.');
		}
		std::cout << "|" << std::setw(10) << value << "|" << std::endl;
	}
	std::cout << "\\" << line << "/" << WHITE << std::endl;

	int	index;
	if (this->_nbContact == 0)
	{
		std::cout << RED << "The phonebook is empty!" << WHITE << std::endl;
		return ;
	}
	std::cout << GREEN << "Type an index to see all informations of it's contact" << std::endl << ">> " << WHITE;
	if (!(std::cin >> index) || index < 0)
	{
		this->handleCtrlD();
		std::cout << RED << "Invalid input" << WHITE << std::endl;
		std::cin.clear();
		return ;
	}
	if (index > 0 && index <= this->_nbContact)
	{
		index -= 1;
		Contact	current = this->_contact[index];
		std::cout << GREEN << "First Name: " << current.get_FirstName() << std::endl;
		std::cout << "Last Name: " << current.get_LastName() << std::endl;
		std::cout << "Nickname: " << current.get_Nickname() << std::endl;
		std::cout << "Phone Number: " << current.get_PhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << current.get_Secret() << WHITE << std::endl;
	}
	else if (index < 1 || index > 8)
	{
		std::cout << RED << "Sorry the index is not in range [1 to 8]" << WHITE << std::endl;
		std::cin.clear();
	}
	else if (index > this->_nbContact)
	{
		std::cout << RED << "Sorry this index is not yet registered" << WHITE << std::endl;
		std::cin.clear();
	}
}
