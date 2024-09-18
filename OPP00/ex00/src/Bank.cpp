/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:32:05 by macarval          #+#    #+#             */
/*   Updated: 2024/09/17 21:01:38 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bank.hpp"

// Constructor & Destructor ===================================================
Bank::Bank( void ) : _liquidity(0) {}

Bank::Bank( Bank const &copy ) { *this = copy; }

Bank::~Bank( void ) {}

// Operators ==================================================================
Bank& Bank::operator=( Bank const &other )
{
	if (this != &other)
		this->_liquidity = other._liquidity;
	return *this;
}

// Getters ====================================================================
double Bank::getLiquidity( void ) const { return this->_liquidity; }

Bank::Account* Bank::getAccount(int id) const
{
	for (std::vector<Bank::Account*>::const_iterator it = _clientAccounts.begin();
		it != _clientAccounts.end(); ++it)
	{
		if ((**it).getId() == id) {
			return *it;
		}
	}
	std::cerr << RED << "Account " << id << " not found!" << RESET << std::endl;
	return new Account();
}

// Setters ====================================================================
void Bank::setLiquidity(double newLiquidity)
{
	if (newLiquidity > 0)
		this->_liquidity += newLiquidity;
	else
		this->_liquidity -= newLiquidity;
}

// Methods ====================================================================
void Bank::openAccount(double newValue)
{
	int		id = 1;
	double	tax = 0;

	if (!_clientAccounts.empty())
	{
		std::vector<Account *>::iterator it = _clientAccounts.end() - 1;
		id = (**it).getId() + 1;
	}

	tax = newValue * 0.05;
	this->_liquidity += tax;

	Account	*newAccount = new Account(id, newValue - tax);
	_clientAccounts.push_back(newAccount);

	std::cout << GREEN << "New Account created : " << *newAccount;
}

void Bank::closeAccount(int id)
{
	for (std::vector<Account*>::iterator it = _clientAccounts.begin();
		it != _clientAccounts.end(); ++it)
	{
		if ((**it).getId() == id) {
			delete *it;
			_clientAccounts.erase(it);
			std::cout << YELLOW << "Account " << id << " closed!";
			std::cout << RESET << std::endl;
			return ;
		}
	}
	std::cerr << RED << "Account " << id << " not found!" << RESET << std::endl;
}

void Bank::giveLoan(int id, double value)
{
	if (value < 0)
		std::cerr << RED << "Can't loan negative values!" << RESET << std::endl;
	else if (value > this->_liquidity)
		std::cerr << RED << "Your loan request was denied!" << RESET << std::endl;
	else
	{
		Account *account = getAccount(id);
		if (account->getId() != -1)
		{
			account->_value += value;
			this->_liquidity -= value;
			std::cout << GREEN << "Loan granted successfully!";
			std::cout << RESET << std::endl;
		}
	}
}

std::ostream& operator<<(std::ostream& p_os, const Bank& p_bank)
{
	p_os << YELLOW << "Bank informations : " << std::endl;
	p_os << "Liquidity : " << p_bank._liquidity << RESET << std::endl;

	for (std::vector<Bank::Account*>::const_iterator it = p_bank._clientAccounts.begin();
			it != p_bank._clientAccounts.end(); ++it)
		p_os << **it;

	return (p_os);
}
