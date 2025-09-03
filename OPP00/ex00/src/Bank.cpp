/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:32:05 by macarval          #+#    #+#             */
/*   Updated: 2025/09/03 13:26:06 by macarval         ###   ########.fr       */
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
	{
		this->_liquidity = other._liquidity;
		this->_clientAccounts = other._clientAccounts;
	}

	return *this;
}

Bank::Account& Bank::operator[](int id)
{
	if (_clientAccounts.find(id) == _clientAccounts.end())
		throw NotFoundException(id);

	return *(_clientAccounts[id]);
}

std::ostream& operator<<(std::ostream& p_os, const Bank& p_bank)
{
	p_os << YELLOW << "Bank informations : " << std::endl;
	p_os << "Liquidity : " << p_bank._liquidity << RESET << std::endl;

	for (std::map<int, Bank::Account*>::const_iterator it = p_bank._clientAccounts.begin();
			it != p_bank._clientAccounts.end(); ++it)
		p_os << *(it->second);

	return (p_os);
}

// Getters ====================================================================
double Bank::getLiquidity( void ) const { return this->_liquidity; }

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
	double	tax = newValue * 0.05;

	if (!_clientAccounts.empty())
		id = _clientAccounts.rbegin()->first + 1;

	this->_liquidity += tax;

	Account	*newAccount = new Account(id, newValue - tax);
	_clientAccounts[id] = newAccount;

	std::cout << GREEN << "New Account created : " << *newAccount;
}

void Bank::closeAccount(int id)
{
	std::map<int, Account*>::iterator it = _clientAccounts.find(id);

	if (it != _clientAccounts.end())
	{
		delete it->second;
		_clientAccounts.erase(it);

		std::cout << YELLOW << "Account " << id << " closed!";
		std::cout << RESET << std::endl;
		
		return ;
	}

	std::cerr << RED << "Can't close account! " << RESET;
	throw NotFoundException(id);
}

void Bank::giveLoan(int id, double value)
{
	if (value < 0)
		throw std::runtime_error("Can't loan negative values!");

	if (value > this->_liquidity)
		throw std::runtime_error("Insufficient bank funds!");

	if (_clientAccounts.find(id) == _clientAccounts.end())
	{
		std::cerr << RED << "Loan denied! " << RESET;
		throw NotFoundException(id);
	}

	Account *account = _clientAccounts[id];
	if (account->getId() != -1)
	{
		account->deposit(value);
		this->_liquidity -= value;
		std::cout << GREEN << "Loan granted successfully!";
		std::cout << RESET << std::endl;
	}
}

Bank::NotFoundException::NotFoundException(int id)
{
	std::ostringstream oss;
	oss << "Account " << YELLOW << id << RED << " not found!" << RESET;
	message = oss.str();
}

const char* Bank::NotFoundException::what() const throw()
{
	return message.c_str();
}
