/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:46:05 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/03 18:11:10 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "PhoneBook constructor called" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook destructor called" << std::endl;
}

int	PhoneBook::get_NbContact(void) const
{
	return this->_NbContact;
}

void	PhoneBook::set_NbContact(int i)
{
	this->_NbContact = i;
	return ;
}

void	PhoneBook::add(void)
{
	std::string	input;
	int			index;

	if (this->get_NbContact() == 7)
	{
		// index = this->get_NbContact() + 1;
		index = (index + 1 ) % 7;
	}
	else
	{
		index = this->get_NbContact() + 1;
		this->set_NbContact(index);
	}

	do
	{
		std::cout << "First Name: ";
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "This can't be null, please try again." << std::endl;
		}
	} while (input.empty());
	this->_contact[index].set_FirstName(input);

	do
	{
		std::cout << "Last Name: ";
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "This can't be null, please try again." << std::endl;
		}
	} while (input.empty());
	this->_contact[index].set_LastName(input);

	do
	{
		std::cout << "Nickname: ";
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "This can't be null, please try again." << std::endl;
		}
	} while (input.empty());
	this->_contact[index].set_Nickname(input);

	do
	{
		std::cout << "Phone Number: ";
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "This can't be null, please try again." << std::endl;
		}
	} while (input.empty());
	this->_contact[index].set_PhoneNumber(input);

	do
	{
		std::cout << "Darkest Secret: ";
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "This can't be null, please try again." << std::endl;
			std::cin.ignore();
			std::cin.clear();
		}
	} while (input.empty());
	this->_contact[index].set_Secret(input);
}

void	PhoneBook::search(void) const
{
	std::string	line(43, '-');
	std::cout << "/" << line << "\\" << std::endl;
	std::cout << "|" << std::setw(10) << "INDEX";
	std::cout << "|" << std::setw(10) << "FIRST NAME";
	std::cout << "|" << std::setw(10) << "LAST NAME";
	std::cout << "|" << std::setw(10) << "NICKNAME" << "|" << std::endl;
	int	i = 0;
	while (i <= this->get_NbContact())
	{
		std::cout << "|" << std::setw(10) << i;
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
		i++;
	}
	std::cout << "\\" << line << "/" << std::endl;

	std::string	tmp;


	std::cout << "Type an index to see all informations of it's contact" << std::endl << ">> ";
	int	index;
	if (!(std::cin >> index) && index < 0)
	{
		std::cin.clear();
		std::cin.ignore();
		return ;
	}
	if (index < 0 || index > 7)
	{
		std::cout << "Sorry the index is not in range [0 to 7]" << std::endl;
		std::cin.clear();
		std::cin.ignore();
		return ;
	}
	if (index > this->_NbContact)
	{
		std::cout << "Sorry this index is not yet registered" << std::endl;
		std::cin.clear();
		std::cin.ignore();
		return ;
	}
	std::cout << "First Name: " << this->_contact[index].get_FirstName() << std::endl;
	std::cout << "Last Name: " << this->_contact[index].get_LastName() << std::endl;
	std::cout << "Nickname: " << this->_contact[index].get_Nickname() << std::endl;
	std::cout << "Phone Number: " << this->_contact[index].get_PhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->_contact[index].get_Secret() << std::endl;
}
