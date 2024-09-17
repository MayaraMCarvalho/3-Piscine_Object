/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:31:52 by macarval          #+#    #+#             */
/*   Updated: 2024/09/17 16:40:00 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

// Constructor & Destructor ===================================================
Account::Account( void ) : _id(-1), _value(0) {}

Account::Account(int id, double value) : _id(id), _value(value) {}

Account::Account( Account const &copy ) { *this = copy; }

Account::~Account( void ) {}

// Operators ==================================================================
Account& Account::operator=( Account const &other )
{
	if (this != &other)
	{
		this->_id = other._id;
		this->_value = other._value;
	}
	return *this;
}

// Getters ====================================================================
int Account::getId( void ) const { return this->_id; }

double Account::getValue( void ) const { return this->_value; }

// Methods ====================================================================

std::ostream& operator<<(std::ostream& p_os, const Account& p_account)
{
	if (p_account._id > 0)
	{
		p_os << PURPLE << "[" << p_account._id << "] - [";
		p_os << std::fixed << std::setprecision(2);
		p_os << p_account._value << "]" << RESET << std::endl;
	}
	return (p_os);
}

