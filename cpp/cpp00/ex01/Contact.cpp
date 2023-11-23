/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:46:07 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/06 13:17:35 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	// std::cout << "Contact constructor called" << std::endl;
}

Contact::~Contact(void)
{
	// std::cout << "Contact destructor called" << std::endl;
}

std::string	Contact::get_FirstName(void) const
{
	return this->_FirstName;
}

void	Contact::set_FirstName(std::string new_firstname)
{
	this->_FirstName = new_firstname;
	return ;
}

std::string	Contact::get_LastName(void) const
{
	return this->_LastName;
}

void	Contact::set_LastName(std::string new_lastname)
{
	this->_LastName = new_lastname;
	return ;
}

std::string	Contact::get_Nickname(void) const
{
	return this->_Nickname;
}

void	Contact::set_Nickname(std::string new_nickname)
{
	this->_Nickname = new_nickname;
	return ;
}

std::string	Contact::get_PhoneNumber(void) const
{
	return this->_PhoneNumber;
}

void	Contact::set_PhoneNumber(std::string new_phonenumber)
{
	this->_PhoneNumber = new_phonenumber;
	return ;
}

std::string	Contact::get_Secret(void) const
{
	return this->_Secret;
}

void	Contact::set_Secret(std::string new_secret)
{
	this->_Secret = new_secret;
	return ;
}