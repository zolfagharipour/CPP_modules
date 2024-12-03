/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:14:09 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/05/21 12:49:31 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

Account::Account (int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	_nbAccounts ++;
	_totalAmount += initial_deposit;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<<";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account (void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<<";amount:" << this->_amount << ";closed" << std::endl;
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts()
			<< ";total:" << Account::getTotalAmount()
			<< ";deposits:" << Account::getNbDeposits()
			<< ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit)
{
	
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";p_amount:" << this->_amount 
			<< ";deposits:" << deposit
			<< ";amount:" << this->_amount + deposit 
			<< ";nb_deposits:" << this->_nbDeposits + 1 << std::endl;
	this->_totalNbDeposits++;
	this->_totalAmount +=deposit;
	this->_nbDeposits++;
	this->_amount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount;
	if (withdrawal > this->_amount)
	{
			std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << ";withdrawal:" << withdrawal
		<< ";amount:" << this->_amount - withdrawal 
		<< ";nb_withdrawals:" << this->_nbWithdrawals + 1 << std::endl;
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	this->_totalAmount-=withdrawal;
	this->_totalNbWithdrawals++;
	return (true);
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";amount:" << this->_amount 
			<< ";deposits:" << this->_nbDeposits
			<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp( void )
{
	time_t	t = time(NULL);
	tm *local = localtime(&t);

	std::cout << "[" << local->tm_year + 1900
			<< std::setw(2) << std::setfill('0') << local->tm_mon
			<< std::setw(2) << std::setfill('0') << local->tm_mday << "_"
			<< std::setw(2) << std::setfill('0') << local->tm_hour
			<< std::setw(2) << std::setfill('0') << local->tm_min
			<< std::setw(2) << std::setfill('0') << local->tm_sec << "] ";
}

