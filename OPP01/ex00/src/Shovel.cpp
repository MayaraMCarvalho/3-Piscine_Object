/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shovel.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:51:55 by macarval          #+#    #+#             */
/*   Updated: 2024/09/19 21:10:53 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Shovel.hpp"

// Constructor & Destructor ===================================================

Shovel::Shovel( void ) : numberOfUses(0), userWorker(NULL)
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
		this->numberOfUses = other.numberOfUses;
	}
	return *this;
}

// Getters ====================================================================
Worker* Shovel::getWorker( void ) const
{
	return userWorker;
}

// Setters ====================================================================
void	Shovel::attachWorker(Worker &worker)
{
	this->userWorker = &worker;
}

// Methods ====================================================================
void	Shovel::use( void )
{
	this->numberOfUses++;

	std::cout << PURPLE << "Shovel🛠️  used🕳️  ";
	if (numberOfUses == 1)
		std::cout << "once!";
	else
		std::cout << numberOfUses << " times!";
	std::cout << RESET << std::endl;
}

// Exceptions =================================================================
