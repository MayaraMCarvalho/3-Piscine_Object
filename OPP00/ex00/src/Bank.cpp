/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:32:05 by macarval          #+#    #+#             */
/*   Updated: 2024/09/10 20:17:55 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bank.hpp"

// Constructor & Destructor ===================================================
Bank::Bank( void ) : liquidity(0) {}

Bank::Bank( Bank const &copy )
{
	*this = copy;
}

Bank::~Bank( void ) {}

// Operators ==================================================================
Bank& Bank::operator=( Bank const &other )
{
	if (this != &other)
	{
		this->liquidity = liquidity;
	}
	return *this;
}

// Getters ====================================================================
int Bank::getLiquidity( void ) const { return this->liquidity; }

Account* Bank::getAccount(int id)
{
	for (std::vector<Account*>::iterator it = clientAccounts.begin(); it != clientAccounts.end(); ++it)
	{
		if ((**it).getId() == id) {
			return *it;
		}
	}
	return NULL;
}

// Setters ====================================================================
void Bank::setLiquidity(int newLiquidity)
{
	if (newLiquidity > 0)
		this->liquidity += newLiquidity;
	else
		this->liquidity -= newLiquidity;

}

// Methods ====================================================================
void Bank::openAccount(int newValue)
{
	Account	*newAccount = new Account();
	int		id = 1;

	if (!clientAccounts.empty())
	{
		std::vector<Account *>::iterator it = clientAccounts.end() - 1;
		id = (**it).getId() + 1;
	}

	this->liquidity += newValue * 0.05;

	newAccount->setId(id);
	newAccount->setValue(newValue * 0.95);

	clientAccounts.push_back(newAccount);

	std::cout << "New Account created : " << *newAccount << std::endl;
}

void Bank::closeAccount(int id)
{
	for (std::vector<Account*>::iterator it = clientAccounts.begin(); it != clientAccounts.end(); ++it)
	{
		if ((**it).getId() == id) {
			delete *it;
			clientAccounts.erase(it);
			return ;
		}
	}
}

std::ostream& operator<<(std::ostream& p_os, const Bank& p_bank)
{
	p_os << "Bank informations : " << std::endl;
	p_os << "Liquidity : " << p_bank.liquidity << std::endl;

	for (std::vector<Account*>::const_iterator it = p_bank.clientAccounts.begin();
			it != p_bank.clientAccounts.end(); ++it)
		p_os << **it << std::endl;

	return (p_os);
}
