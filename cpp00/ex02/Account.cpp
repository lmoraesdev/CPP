#include "Account.hpp"
#include <iostream>
#include <sstream>
#include <ctime>
#include <string>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account :: Account(int initial_deposit){
	this->_accountIndex = this->_nbAccounts;
	this->_nbAccounts += 1;
	this->_amount = initial_deposit;
	this->_totalAmount += initial_deposit;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created"<< std::endl;
}

Account :: ~Account(){
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed"<< std::endl;
	this->_totalAmount -= this->_amount;
}

std::string normTime(int number){
	std::stringstream	sBuffer;
	std::string 		buffer;

	if (number < 10)
		sBuffer << "0";
	sBuffer << number;
	buffer = sBuffer.str();
	return (buffer);
}

void	Account::_displayTimestamp(void){
	std::stringstream to_log;
	to_log << "[";
	std::time_t current_time = std::time(NULL);
	std::tm *ltm = localtime(&current_time);
	to_log << ltm->tm_year + 1900 << normTime(ltm->tm_mon + 1) << normTime(ltm->tm_mday);
	to_log << "_" << normTime(ltm->tm_hour) << normTime(ltm->tm_min) << normTime(ltm->tm_sec)<< "] ";
	std::cout << to_log.str();
}

int	Account::getNbAccounts(void){
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void){
	return (Account::_totalAmount);

}

int	Account::getNbDeposits(void){
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void){
	return (Account::_totalNbDeposits);
}

void	Account::displayAccountsInfos(void){
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex<< ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (deposit > 0){
		this->_amount += deposit;
		this->_nbDeposits += 1;
		this->_totalAmount += deposit;
		this->_totalNbDeposits += 1;
	}
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex<< ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (withdrawal > 0  && this->_amount >= withdrawal){
		this->_amount -= withdrawal;
		this->_nbWithdrawals += 1;
		this->_totalNbWithdrawals += 1;
		std::cout << "withdrawal:" << withdrawal<< ";";
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawal:" << this->_nbWithdrawals<< std::endl;
		return (true);
	}
	std::cout << "withdrawal:refused" << std::endl;
	return (false);
}

int	Account::checkAmount(void)const{
	return (this->_amount);
}

void	Account::displayStatus(void)const{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex<< ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}
