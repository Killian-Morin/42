/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:25:30 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/20 15:06:28 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <iostream>
#include <ctime>

#define YEL "\e[0;33m"
#define WHT "\e[0;37m"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/*
	FONCTIONS PUBLIC
*/
int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	/*std::cout << "accounts:" << YEL << Account::_nbAccounts << WHT \
		<< ";total:" << YEL << Account::_totalAmount << WHT \
		<< ";deposits:" << YEL << Account::_totalNbDeposits << WHT \
		<< ";withdrawals:" << YEL << Account::_totalNbWithdrawals << WHT<< std::endl;*/
	std::cout << "accounts:" << Account::_nbAccounts \
		<< ";total:" << Account::_totalAmount \
		<< ";deposits:" << Account::_totalNbDeposits \
		<< ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	this->_accountIndex = this->_nbAccounts;
	this->_totalAmount += initial_deposit;
	this->_amount = initial_deposit;
	/*std::cout << "index:" << YEL << this->_nbAccounts++ << WHT \
		<< ";amount:" << YEL << initial_deposit << WHT \
		<< ";created" << std::endl;*/
	std::cout << "index:" << this->_nbAccounts++ \
		<< ";amount:" << initial_deposit \
		<< ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	/*std::cout << "index:" << YEL << this->_accountIndex << WHT \
		<< ";amount:" << YEL << this->_amount << WHT \
		<< ";closed" << std::endl;*/
	std::cout << "index:" << this->_accountIndex \
		<< ";amount:" << this->_amount \
		<< ";closed" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	this->_nbDeposits++;
	this->_totalNbDeposits++;
	_displayTimestamp();
 	/*std::cout << "index:" << YEL << this->_accountIndex << WHT \
		<< ";p_amount:" << YEL << this->_amount << WHT \
		<< ";deposit:" << YEL << deposit << WHT \
		<< ";amount:" <<  YEL << this->_amount + deposit << WHT \
		<< ";nb_deposits:" << YEL << this->_nbDeposits << WHT << std::endl;*/
	std::cout << "index:" << this->_accountIndex \
		<< ";p_amount:" << this->_amount \
		<< ";deposit:" << deposit \
		<< ";amount:" << this->_amount + deposit \
		<< ";nb_deposits:" << this->_nbDeposits << std::endl;
	this->_amount += deposit;
	this->_totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal <= this->_amount)
	{
		this->_nbWithdrawals++;
		this->_totalNbWithdrawals++;
		_displayTimestamp();
 		/*std::cout << "index:" << YEL << this->_accountIndex << WHT \
			<< ";p_amount:" << YEL << this->_amount + withdrawal << WHT \
			<< ";withdrawal:" << YEL << withdrawal << WHT \
			<< ";amount:" <<  YEL << this->_amount << WHT \
			<< ";nb_withdrawal:" << YEL << this->_nbWithdrawals << WHT << std::endl;*/
		std::cout << "index:" << this->_accountIndex \
			<< ";p_amount:" << this->_amount \
			<< ";withdrawal:" << withdrawal \
			<< ";amount:" << this->_amount - withdrawal \
			<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		this->_amount -= withdrawal;
		this->_totalAmount -= withdrawal;
		return (true);
	}
	else
	{
		_displayTimestamp();
 		/*std::cout << "index:" << YEL << this->_accountIndex << WHT \
			<< ";p_amount:" << YEL << this->_amount << WHT \
			<< ";withdrawal:refused" << std::endl;*/
		std::cout << "index:" << this->_accountIndex \
			<< ";p_amount:" << this->_amount \
			<< ";withdrawal:refused" << std::endl;
		return (false);
	}
}

int	Account::checkAmount(void) const
{
	return this->_amount;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
 	/*std::cout << "index:" << YEL << this->_accountIndex << WHT \
		<< ";amount:" << YEL << this->_amount << WHT \
		<< ";deposits:" << YEL << this->_nbDeposits << WHT \
		<< ";withdrawal:" << YEL << this->_nbWithdrawals << WHT << std::endl;*/
	std::cout << "index:" << this->_accountIndex \
		<< ";amount:" << this->_amount << \
		";deposits:" << this->_nbDeposits << \
		";withdrawals:" << this->_nbWithdrawals << std::endl;
}

/*
	FONCTIONS PRIVATE
*/
//date format is: YYYYMMDD_HHMMSS
void	Account::_displayTimestamp(void)
{
	std::time_t	now;
	std::tm 	timeinfo;
	char		str[20];

	now = std::time(NULL);
	timeinfo = *std::localtime(&now);
	std::strftime(str, 20, "[%Y%m%d_%H%M%S] ", &timeinfo);

	std::cout << str;
}

Account::Account(void)
{
	std::cout << "Classic constructor" << std::endl;
}
