/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:45:57 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 09:06:40 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iomanip>
#include <iostream>
#include <istream>

#include "Color.hpp"

class Contact {

	private:
		std::string	_FirstName;
		std::string	_LastName;
		std::string	_Nickname;
		std::string	_PhoneNumber;
		std::string	_Secret;

	public:
		//Constructor/Destructor
		Contact(void);
		~Contact(void);

		//Getters/Setters
		std::string	get_FirstName(void) const;
		void		set_FirstName(std::string new_firstname);
		std::string	get_LastName(void) const;
		void		set_LastName(std::string new_lastname);
		std::string	get_Nickname(void) const;
		void		set_Nickname(std::string new_nickname);
		std::string	get_PhoneNumber(void) const;
		void		set_PhoneNumber(std::string new_phonenumber);
		std::string	get_Secret(void) const;
		void		set_Secret(std::string new_secret);
};

#endif //CONTACT_HPP
