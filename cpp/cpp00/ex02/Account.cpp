/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:25:30 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/08 16:51:19 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <iostream>
#include <ctime>

#ifndef SHOWMSG
# define SHOWMSG 1
#endif

#define RESET "\e[0m"
#define YELLOW "\e[0;33m"

#define COLOR(text, color) color << text << RESET

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/*
	FONCTIONS PUBLIC
*/
int	Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return (_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void) {

	_displayTimestamp();

	if (SHOWMSG)
		std::cout << "accounts:" << COLOR(Account::_nbAccounts, YELLOW) << \
			";total:" << COLOR(Account::_totalAmount, YELLOW) << \
			";deposits:" << COLOR(Account::_totalNbDeposits, YELLOW) << \
			";withdrawals:" << COLOR(Account::_totalNbWithdrawals, YELLOW) << std::endl;
	else
		std::cout << "accounts:" << Account::_nbAccounts << \
			";total:" << Account::_totalAmount << \
			";deposits:" << Account::_totalNbDeposits << \
			";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit) {

	_displayTimestamp();

	this->_accountIndex = this->_nbAccounts;
	this->_totalAmount += initial_deposit;
	this->_amount = initial_deposit;

	if (SHOWMSG)
		std::cout << "index:" << COLOR(this->_nbAccounts++, YELLOW) << \
			";amount:" << COLOR(initial_deposit, YELLOW) << \
			";created" << std::endl;
	else
		std::cout << "index:" << this->_nbAccounts++ << \
			";amount:" << initial_deposit << \
			";created" << std::endl;
}

Account::~Account(void) {

	_displayTimestamp();

	if (SHOWMSG)
		std::cout << "index:" << COLOR(this->_accountIndex, YELLOW) << \
			";amount:" << COLOR(this->_amount, YELLOW) << \
			";closed" << std::endl;
	else
		std::cout << "index:" << this->_accountIndex << \
			";amount:" << this->_amount << \
			";closed" << std::endl;
}

void	Account::makeDeposit(int deposit) {

	this->_nbDeposits++;
	this->_totalNbDeposits++;

	_displayTimestamp();

	if (SHOWMSG)
		std::cout << "index:" << COLOR(this->_accountIndex, YELLOW) << \
			";p_amount:" << COLOR(this->_amount, YELLOW) <<  \
			";deposit:" << COLOR(deposit, YELLOW) << \
			";amount:" << COLOR(this->_amount + deposit, YELLOW) << \
			";nb_deposits:" << COLOR(this->_nbDeposits, YELLOW) << std::endl;
	else
		std::cout << "index:" << this->_accountIndex << \
			";p_amount:" << this->_amount <<  \
			";deposit:" << deposit << \
			";amount:" << this->_amount + deposit << \
			";nb_deposits:" << this->_nbDeposits << std::endl;

	this->_amount += deposit;
	this->_totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal) {

	if (withdrawal <= this->_amount) {
		this->_nbWithdrawals++;
		this->_totalNbWithdrawals++;

		_displayTimestamp();

		if (SHOWMSG)
			std::cout << "index:" << COLOR(this->_accountIndex, YELLOW) << \
				";p_amount:" << COLOR(this->_amount + withdrawal, YELLOW) << \
				";withdrawal:" << COLOR(withdrawal, YELLOW) << \
				";amount:" << COLOR(this->_amount, YELLOW) << \
				";nb_withdrawal:" << COLOR(this->_nbWithdrawals, YELLOW) << std::endl;
		else
			std::cout << "index:" << this->_accountIndex << \
				";p_amount:" << this->_amount + withdrawal << \
				";withdrawal:" << withdrawal << \
				";amount:" << this->_amount << \
				";nb_withdrawal:" << this->_nbWithdrawals << std::endl;

		this->_amount -= withdrawal;
		this->_totalAmount -= withdrawal;

		return (true);
	}
	else
	{
		_displayTimestamp();

		if (SHOWMSG)
			std::cout << "index:" << COLOR(this->_accountIndex, YELLOW) << \
				";p_amount:" << COLOR(this->_amount, YELLOW) << \
				";withdrawal:refused" << std::endl;
		else
			std::cout << "index:" << this->_accountIndex << \
				";p_amount:" << this->_amount << \
				";withdrawal:refused" << std::endl;

		return (false);
	}
}

int	Account::checkAmount(void) const {
	return this->_amount;
}

void	Account::displayStatus(void) const {

	_displayTimestamp();

	if (SHOWMSG)
		std::cout << "index:" << COLOR(this->_accountIndex, YELLOW) << \
			";amount:" << COLOR(this->_amount, YELLOW) << \
			";deposits:" << COLOR(this->_nbDeposits, YELLOW) << \
			";withdrawal:" << COLOR(this->_nbWithdrawals, YELLOW) << std::endl;
	else
		std::cout << "index:" << this->_accountIndex << \
			";amount:" << this->_amount << \
			";deposits:" << this->_nbDeposits << \
			";withdrawal:" << this->_nbWithdrawals << std::endl;
}

/*
	FONCTIONS PRIVATE
*/
//date format is: YYYYMMDD_HHMMSS
void	Account::_displayTimestamp(void) {

	std::time_t	now;
	std::tm 	timeinfo;
	char		str[20];

	now = std::time(NULL);
	timeinfo = *std::localtime(&now);
	std::strftime(str, 20, "[%Y%m%d_%H%M%S] ", &timeinfo);

	std::cout << str;
}

Account::Account(void) {
	std::cout << "Classic constructor" << std::endl;
}
