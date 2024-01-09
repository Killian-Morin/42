/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:42:36 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 15:35:49 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

Character::Character(void) : _name("defaultCharacter"), _idxInventory(0), _idxUnequiped(0) {

	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;

	for (int i = 0; i < 4; i++)
		this->_unequipedInventory[i] = NULL;

	if (SHOWMSG)
		std::cout << COLOR("Character default constructor called.", GREEN) << std::endl;
}

Character::Character(Character const& src) {

	this->_name = src._name;

	for (int i = 0; i < 4; i++) {
		delete this->_inventory[i];
		if (src._inventory[i] != NULL)
			this->_inventory[i] = src._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	this->_idxInventory = src._idxInventory;

	for (int i = 0; i < 4; i++) {
		delete this->_unequipedInventory[i];
		if (src._unequipedInventory[i] != NULL)
			this->_unequipedInventory[i] = src._unequipedInventory[i]->clone();
		else
			this->_unequipedInventory[i] = NULL;
	}
	this->_idxUnequiped = src._idxUnequiped;

	if (SHOWMSG)
		std::cout << COLOR("Character copy constructor called.", GREEN) << std::endl;
}

Character&	Character::operator=(Character const& rhs) {

	if (this != &rhs) {
		this->_name = rhs._name;

		for (int i = 0; i < 4; i++) {
			delete this->_inventory[i];
			if (rhs._inventory[i] != NULL)
				this->_inventory[i] = rhs._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
		this->_idxInventory = rhs._idxInventory;

		for (int i = 0; i < 4; i++) {
			delete this->_unequipedInventory[i];
			if (rhs._unequipedInventory[i] != NULL)
				this->_unequipedInventory[i] = rhs._unequipedInventory[i]->clone();
			else
				this->_unequipedInventory[i] = NULL;
		}
		this->_idxUnequiped = rhs._idxUnequiped;
	}

	if (SHOWMSG)
		std::cout << COLOR("Character assignation operator called.", GREEN) << std::endl;

	return (*this);
}

Character::~Character(void) {

	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = NULL;

		if (this->_unequipedInventory[i])
			delete this->_unequipedInventory[i];
		this->_unequipedInventory[i] = NULL;
	}

	if (SHOWMSG)
		std::cout << COLOR("Character default destructor called.", RED) << std::endl;
}

/* ************************************************************************** */
/*                           PARAMETRIC CONSTRUCTOR                           */
/* ************************************************************************** */

Character::Character(std::string const& name) : _name(name), _idxInventory(0), _idxUnequiped(0) {

	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for (int i = 0; i < 4; i++)
		this->_unequipedInventory[i] = NULL;

	if (SHOWMSG)
		std::cout << COLOR("Character parametric constructor called.", GREEN) << std::endl;
}

/* ************************************************************************** */
/*                        OVERLOADED HERITED FUNCTIONS                        */
/* ************************************************************************** */

std::string const& Character::getName(void) const {

	return (this->_name);
}

void	Character::equip(AMateria* m) {

	if (this->_idxInventory >= 4) {
		std::cout << "❌ " << COLOR(this->_name, MAGENTA) << \
			COLOR("'s inventory is full, couldn't equip this Materia.", RED) << std::endl;
		delete m;
	}
	else {
		this->_inventory[this->_idxInventory] = m;
		this->_idxInventory++;

		std::cout << "🎉 " << COLOR(this->_name, MAGENTA) << COLOR(": equiped the Materia of type ", YELLOW) << \
			COLOR(this->_inventory[this->_idxInventory - 1]->getType(), MAGENTA) << "." << std::endl;
	}
}

void	Character::unequip(int idx) {

	if (this->_inventory[idx] == NULL) {
		std::cout << "❌ " << COLOR(this->_name, MAGENTA) << \
			COLOR(": no Materia equiped at this index of the inventory, range is 0 - " << \
			this->_idxInventory - 1 << ".", RED) << std::endl;
		return ;
	}

	if (idx >= 0 && idx < 4) {
		this->_idxInventory--;

		handleUnequipedInventory(idx);
		return ;
	}
	else {
		std::cout << "❌ " << COLOR(this->_name, MAGENTA) << \
			COLOR(": the index is not within range of the inventory (0 - 3).", RED) << std::endl;
	}
}

void	Character::use(int idx, ICharacter& target) {

	if (this->_inventory[idx] == NULL && idx >= 0 && idx < 4) {
		std::cout << "❌ " << COLOR(this->_name, MAGENTA) << \
			COLOR(": no Materia to use at this index of the inventory, range is 0 - " << \
			this->_idxInventory - 1 << ".", RED) << std::endl;
		return ;
	}

	if (idx >= 0 && idx < 4) {
		this->_inventory[idx]->use(target);

		std::cout << "🎉 " << COLOR(this->_name, MAGENTA) << \
			COLOR(": uses ", YELLOW) << COLOR(this->_inventory[idx]->getType(), MAGENTA) << COLOR(".", YELLOW) << std::endl;
		return ;
	}
	else {
		std::cout << "❌ " << COLOR(this->_name, MAGENTA) << \
			COLOR(": the index is not within range of the inventory (0 - 3). We can't use any Materia.", RED) << std::endl;
	}
}

void	Character::handleUnequipedInventory(int idx) {

	if (this->_idxUnequiped == 4) {
		delete this->_unequipedInventory[0];

		for (int i = 0; i < this->_idxUnequiped - 1; i++)
			this->_unequipedInventory[i] = this->_unequipedInventory[i + 1];
		this->_unequipedInventory[this->_idxUnequiped - 1] = this->_inventory[idx];
		this->_inventory[idx] = NULL;

		std::cout << "🎉 " << COLOR(this->_name, MAGENTA) << COLOR(": unequiped the Materia ", YELLOW) << \
			COLOR(this->_unequipedInventory[this->_idxUnequiped - 1]->getType(), MAGENTA) << COLOR(".", YELLOW) << std::endl;
	}
	else {
		std::cout << "🎉 " << COLOR(this->_name, MAGENTA) << COLOR(": unequiped the Materia ", YELLOW) << \
			COLOR(this->_inventory[idx]->getType(), MAGENTA) << COLOR(".", YELLOW) << std::endl;

		this->_unequipedInventory[this->_idxUnequiped] = this->_inventory[idx];
		this->_inventory[idx] = NULL;
		this->_idxUnequiped++;
	}
}
