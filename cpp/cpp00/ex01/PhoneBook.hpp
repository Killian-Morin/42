/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:46:02 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/07 14:18:31 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#define RED "\033[31m"
#define GREEN "\e[0;32m"
#define BLUE "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CYAN "\e[0;36m"
#define WHITE "\033[37m"

#include <string>
#include <iomanip>
#include <iostream>
#include <istream>
#include <cstdlib>
#include <cctype>

#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	handleCtrlD(void) const;
		int		notValidPhoneNumber(std::string input) const;

		void	add(void);
		void	search(void) const;

	private:
		Contact	_contact[8];
		int		_nbContact;
		int		_oldestContact;
};

#endif
