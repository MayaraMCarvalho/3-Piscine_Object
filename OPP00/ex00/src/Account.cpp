/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:31:52 by macarval          #+#    #+#             */
/*   Updated: 2024/09/10 20:42:59 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

// Constructor & Destructor ===================================================
Account::Account( void ) : id(-1), value(0) {}

Account::Account( Account const &copy ) { *this = copy; }

Account::~Account( void ) {}

// Operators ==================================================================
Account& Account::operator=( Account const &other )
{
	if (this != &other)
	{
		this->id = other.id;
		this->value = other.value;
	}
	return *this;
}

// Getters ====================================================================
int Account::getId( void ) const { return this->id; }

double Account::getValue( void ) const { return this->value; }


// Setters ====================================================================
void Account::setId(int newId) { this->id = newId; }

void Account::setValue(double newValue)
{
	if (newValue > 0)
		this->value += newValue;
	else
		this->value -= newValue;
}

// Methods ====================================================================

std::ostream& operator<<(std::ostream& p_os, const Account& p_account)
{
	if (p_account.id > 0)
		p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
	return (p_os);
}

