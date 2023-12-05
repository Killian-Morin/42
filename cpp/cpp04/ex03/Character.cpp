/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:42:36 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/05 16:54:42 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	std::cout << COLOR("Character default constructor called.", BLUE) << std::endl;
}

Character::Character(const Character& src)
{
	*this = src;
	std::cout << COLOR("Character copy constructor called.", BLUE) << std::endl;
}

Character&	Character::operator=(const Character& rhs)
{
	if (this != &rhs)
	{
		// Do the assignment here
	}
	std::cout << COLOR("Character assignation operator called.", BLUE) << std::endl;
	return (*this);
}

Character::~Character(void)
{
	std::cout << COLOR("Character default destructor called.", RED) << std::endl;
}

std::string const& Character::getName(void) const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{

}

void	Character::unequip(int idx)
{

}

void	Character::use(int idx, ICharacter& target)
{
	
}
