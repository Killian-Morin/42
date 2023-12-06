/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:42:36 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/06 16:52:35 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/* ************************************************************************** */
/*                  CANONIC METHODS and SPECIAL CONSTRUCTORS                  */
/* ************************************************************************** */

Character::Character(void) : _name("defaultCharacter"), _idxInventory(0), _idxUnequiped(0)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for (int i = 0; i < 4; i++)
		this->_unequipedInventory[i] = NULL;

	std::cout << COLOR("Character default constructor called.", BLUE) << std::endl;
}

Character::Character(std::string const& name) : _name(name), _idxInventory(0), _idxUnequiped(0)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for (int i = 0; i < 4; i++)
		this->_unequipedInventory[i] = NULL;

	std::cout << COLOR("Character parametric constructor called.", BLUE) << std::endl;
}

Character::Character(const Character& src)
{
	this->_name = src._name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = src._inventory[i];
	this->_idxInventory = src._idxInventory;
	for (int i = 0; i < 4; i++)
		this->_unequipedInventory[i] = src._unequipedInventory[i];
	this->_idxUnequiped = src._idxUnequiped;

	std::cout << COLOR("Character copy constructor called.", BLUE) << std::endl;
}

Character&	Character::operator=(const Character& rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		for (int i = 0; i < 4; i++)
			this->_inventory[i] = rhs._inventory[i];
		this->_idxInventory = rhs._idxInventory;
		for (int i = 0; i < 4; i++)
			this->_unequipedInventory[i] = rhs._unequipedInventory[i];
		this->_idxUnequiped = rhs._idxUnequiped;
	}

	std::cout << COLOR("Character assignation operator called.", BLUE) << std::endl;
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = NULL;
		if (this->_unequipedInventory[i])
			delete this->_unequipedInventory[i];
		this->_unequipedInventory[i] = NULL;
	}
	std::cout << COLOR("Character default destructor called.", RED) << std::endl;
}

/* ************************************************************************** */
/*                              MEMBERS FUNCTIONS                             */
/* ************************************************************************** */

std::string const& Character::getName(void) const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	if (this->_idxInventory >= 4)
	{
		std::cout << "❌ " << COLOR(this->_name, MAGENTA) << \
			COLOR("'s inventory is full, couldn't equip this Materia.", RED) << std::endl;
	}
	else
	{
		this->_idxInventory++;
		// delete this->_inventory[i]; //check for PH
		this->_inventory[this->_idxInventory] = m;
		std::cout << "🎉 " << COLOR(this->_name, MAGENTA) << \
			COLOR(": equiped the Materia of type ", YELLOW) << COLOR(m->getType(), MAGENTA) << "." << std::endl;
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 4)
	{
		std::cout << "❌ " << COLOR(this->_name, MAGENTA);
		if (this->_inventory[idx] == NULL)
			std::cout << COLOR(": no Materia equiped at this index of the inventory, range is 0 - " \
				<< this->_idxInventory << ".", RED) << std::endl;
		else
			std::cout << COLOR(": the index is not within range of the inventory (0 - 4).", RED) << std::endl;
	}
	else
	{
		this->_idxInventory--;
		handleUnequipedInventory(idx);
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 4)
	{
		std::cout << "❌ " << COLOR(this->_name, MAGENTA);
		std::cout << COLOR(": the index is not within range of the inventory (0 - 4)." \
		"We can't use any Materia.", RED) << std::endl;
	}
	if (this->_inventory[idx])
	{
		this->_inventory[idx]->use(target);
		std::cout << "🎉 " << COLOR(this->_name, MAGENTA) << \
			COLOR(": uses ", YELLOW) << COLOR(this->_inventory[idx]->getType(), MAGENTA) << COLOR(".", YELLOW) << std::endl;
	}
	else
	{
		std::cout << "❌ " << COLOR(this->_name, MAGENTA);
		std::cout << COLOR(": no Materia to use at this index of the inventory, range is 0 - " \
		<< this->_idxInventory << ".", RED) << std::endl;
	}
}

void	Character::handleUnequipedInventory(int idx)
{
	if (this->_idxUnequiped < 4)
	{
		this->_idxUnequiped++;
		this->_unequipedInventory[this->_idxUnequiped] = this->_inventory[idx];
		this->_inventory[idx] = NULL;
		std::cout << "🎉 " << COLOR(this->_name, MAGENTA) << \
			COLOR(": unequiped the Materia ", YELLOW) << \
			COLOR(this->_unequipedInventory[this->_idxUnequiped]->getType(), MAGENTA) << COLOR(".", YELLOW) << std::endl;
	}
	else
	{
		delete this->_unequipedInventory[3];
		for (int i = 2; i > 0; i--)
			this->_unequipedInventory[i + 1] = this->_unequipedInventory[i];
		this->_unequipedInventory[0] = this->_inventory[idx];
		this->_inventory[idx] = NULL;
		std::cout << "🎉 " << COLOR(this->_name, MAGENTA) << \
			COLOR(": unequiped the Materia ", YELLOW) << \
			COLOR(this->_unequipedInventory[0]->getType(), MAGENTA) << COLOR(".", YELLOW) << std::endl;
	}
}
