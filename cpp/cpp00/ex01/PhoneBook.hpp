/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:46:02 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/06 14:59:57 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#define RED "\033[31m"
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

		int		get_NbContact(void) const;
		void	set_NbContact(int i);

		void	add(void);
		void	search(void) const;

		void	handleCtrlD(void) const;

	private:
		Contact	_contact[8];
		int		_nbContact;
		int		_oldestContact;
};

#endif
