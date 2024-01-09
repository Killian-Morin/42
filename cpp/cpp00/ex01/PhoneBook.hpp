/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:46:02 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 09:06:51 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>
#include <iomanip>
#include <iostream>
#include <istream>
#include <cstdlib>
#include <cctype>

#include "Color.hpp"
#include "Contact.hpp"

class PhoneBook {

	private:
		Contact	_contact[8];
		int		_nbContact;
		int		_oldestContact;

	public:
		//Constructor/Destructor
		PhoneBook(void);
		~PhoneBook(void);

		//Member Functions
		void	handleCtrlD(void) const;
		int		notValidPhoneNumber(std::string input) const;

		void	add(void);
		void	search(void) const;
};

#endif //PHONEBOOK_HPP
