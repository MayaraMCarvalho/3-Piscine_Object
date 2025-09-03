/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:31:52 by macarval          #+#    #+#             */
/*   Updated: 2025/09/03 13:24:22 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bank.hpp"

// Constructor & Destructor ===================================================
Bank::Account::Account( void ) : _id(-1), _value(0) {}

Bank::Account::Account(int id, double value) : _id(id), _value(value) {}

Bank::Account::Account( Account const &copy ) { *this = copy; }

Bank::Account::~Account( void ) {}

// Operators ==================================================================
Bank::Account& Bank::Account::operator=( Account const &other )
{
	if (this != &other)
	{
		this->_id = other._id;
		this->_value = other._value;
	}
	return *this;
}

// Getters ====================================================================
int Bank::Account::getId( void ) const { return this->_id; }

double Bank::Account::getValue( void ) const { return this->_value; }

// Setters ====================================================================
void Bank::Account::deposit(double amount)
{
	this->_value += amount;
}

// Methods ====================================================================

std::ostream& operator<<(std::ostream& p_os, const Bank::Account& p_account)
{
	if (p_account._id > 0)
	{
		p_os << PURPLE << "[" << p_account._id << "] - [";
		p_os << std::fixed << std::setprecision(2);
		p_os << p_account._value << "]" << RESET << std::endl;
	}
	return (p_os);
}
