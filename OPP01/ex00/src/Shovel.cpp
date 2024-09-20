/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shovel.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:51:55 by macarval          #+#    #+#             */
/*   Updated: 2024/09/19 23:25:04 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Shovel.hpp"

// Constructor & Destructor ===================================================

Shovel::Shovel( void ) : _numberOfUses(0), _userWorker(NULL)
{
	std::cout << GREEN << "Shovel🛠️  default created!" << RESET << std::endl;
}

Shovel::~Shovel( void )
{
	std::cout << RED << "Shovel🛠️  destroyed!" << RESET << std::endl;
}

Shovel::Shovel( Shovel const &copy ) { *this = copy; }

// Operators ==================================================================
Shovel& Shovel::operator=( Shovel const &other )
{
	if (this != &other)
	{
		this->_numberOfUses = other._numberOfUses;
	}
	return *this;
}

// Getters ====================================================================
Worker* Shovel::getWorker( void ) const
{
	return _userWorker;
}

// Setters ====================================================================
void	Shovel::attachWorker(Worker &worker)
{
	this->_userWorker = &worker;
}

// Methods ====================================================================
void	Shovel::use( void )
{
	this->_numberOfUses++;

	std::cout << PURPLE << "Shovel🛠️  used🕳️  ";
	if (_numberOfUses == 1)
		std::cout << "once!";
	else
		std::cout << _numberOfUses << " times!";
	std::cout << RESET << std::endl;
}

// Exceptions =================================================================
