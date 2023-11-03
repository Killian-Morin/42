/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:46:02 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/03 15:45:48 by kmorin           ###   ########.fr       */
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

#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook(void);
		~PhoneBook(void);

		int		get_NbContact(void) const;
		void	set_NbContact(int i);

		void	add(void);
		void	search(void) const;


	private:
		Contact	_contact[8];
		int		_NbContact;
};

#endif
