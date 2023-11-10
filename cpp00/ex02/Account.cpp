#include "Account.hpp"
#include <iostream>
#include <sstream>
#include <ctime>
#include <string>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/**
 * The above function is a constructor for the Account class in C++ that
 * initializes the account with an initial deposit and displays the account index,
 * amount, and creation timestamp.
 *
 * @param initial_deposit The initial_deposit parameter is the amount of money that
 * is deposited into the account when it is created.
 */
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

/**
 * The function "normTime" converts an integer representing a time value into a
 * string representation with a leading zero if the number is less than 10.
 */
Account :: ~Account(){
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed"<< std::endl;
	this->_totalAmount -= this->_amount;
}

/**
 * The function "normTime" takes an integer as input and returns a string
 * representation of that integer, with a leading zero if the number is less than
 * 10.
 *
 * @param number The parameter "number" is an integer representing a time value.
 *
 * @return The function `normTime` returns a string.
 */
std::string normTime(int number){
	std::stringstream	sBuffer;
	std::string 		buffer;

	if (number < 10)
		sBuffer << "0";
	sBuffer << number;
	buffer = sBuffer.str();
	return (buffer);
}

/**
 * The function `_displayTimestamp` formats the current time and date into a string
 * and prints it to the console.
 */
void	Account::_displayTimestamp(void){
	std::stringstream to_log;
	to_log << "[";
	std::time_t current_time = std::time(NULL);
	std::tm *ltm = localtime(&current_time);
	to_log << ltm->tm_year + 1900 << normTime(ltm->tm_mon + 1) << normTime(ltm->tm_mday);
	to_log << "_" << normTime(ltm->tm_hour) << normTime(ltm->tm_min) << normTime(ltm->tm_sec)<< "] ";
	std::cout << to_log.str();
}

/**
 * The function returns the number of accounts.
 *
 * @return The number of accounts.
 */
int	Account::getNbAccounts(void){
	return (Account::_nbAccounts);
}
/**
 * The function returns the total amount in the Account class.
 *
 * @return The total amount of the account.
 */

int	Account::getTotalAmount(void){
	return (Account::_totalAmount);

}

/**
 * The function "displayAccountsInfos" displays the current state of all accounts,
 * including the number of accounts, total amount, total number of deposits, and
 * total number of withdrawals.
 *
 * @return The total number of withdrawals made.
 */
int	Account::getNbDeposits(void){
	return (Account::_totalNbDeposits);
}

/**
 * The function "displayAccountsInfos" displays the current state of all accounts,
 * including the number of accounts, total amount, total number of deposits, and
 * total number of withdrawals.
 *
 * @return the total number of withdrawals made.
 */
int	Account::getNbWithdrawals(void){
	return (Account::_totalNbDeposits);
}

/**
 * The function "displayAccountsInfos" displays the current state of all accounts,
 * including the number of accounts, total amount, total number of deposits, and
 * total number of withdrawals.
 */
void	Account::displayAccountsInfos(void){
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

/**
 * The function `makeDeposit` in the `Account` class allows a user to make a
 * deposit into their account and updates the account's balance and deposit count.
 *
 * @param deposit The "deposit" parameter in the makeDeposit function represents
 * the amount of money that is being deposited into the account.
 */
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

/**
 * The function `makeWithdrawal` allows a user to withdraw a specified amount from
 * their account, updating the account balance and withdrawal statistics if the
 * withdrawal is successful.
 *
 * @param withdrawal The "withdrawal" parameter is an integer that represents the
 * amount of money that the account holder wants to withdraw from their account.
 *
 * @return a boolean value. It returns true if the withdrawal is successful and
 * false if the withdrawal is refused.
 */
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

/**
 * The function "checkAmount" returns the value of the private member variable
 * "_amount" in the "Account" class.
 *
 * @return the value of the private member variable `_amount`.
 */
int	Account::checkAmount(void)const{
	return (this->_amount);
}

/**
 * The function "displayStatus" displays the account's index, amount, number of
 * deposits, and number of withdrawals.
 */
void	Account::displayStatus(void)const{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex<< ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}
