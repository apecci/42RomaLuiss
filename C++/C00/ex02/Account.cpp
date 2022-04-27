/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apecci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:28:48 by apecci            #+#    #+#             */
/*   Updated: 2022/04/27 13:28:49 by apecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit){
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _totalAmount;
	std::cout << ";created" << std::endl;
	return ;
}

Account::~Account(){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _totalAmount;
	std::cout << ";closed" << std::endl;
}

int Account::getNbAccounts(){
	return (_nbAccounts);
}

int Account::getTotalAmount(){
	return (_totalAmount);
}

int Account::getNbDeposits(){
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(){
	return (_totalNbWithdrawals);
}

void Account::_displayTimestamp(){
	time_t		t;
	struct tm	*tm;

	t = time(0);
	tm = localtime(&t);
	std::cout << "[" << tm->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << tm->tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2) << tm->tm_mday << "_";
	std::cout << std::setfill('0') << std::setw(2) << tm->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << tm->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << tm->tm_sec << "] ";
	return ;
}

void Account::displayAccountsInfos(){
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals << std::endl;
	return ;
}

void Account::displayStatus() const{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
	return ;
}

void Account::makeDeposit(int deposit){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";deposits:" << deposit;
	std::cout << ";amount:" << _amount + deposit;
	std::cout << ";nb_deposits" << _nbDeposits++ << std::endl;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	return ;
}

bool Account::makeWithdrawal(int withdrawal){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	if (_amount >= withdrawal)
	{
		std::cout << ";withdrawal:" << withdrawal;
		std::cout << ";amount:" << _amount - withdrawal;
		std::cout << ";nb_withdrawals:" << _nbWithdrawals++ << std::endl;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		return (true);
	}
	else
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
}

int Account::checkAmount() const{
	return (_amount);
}