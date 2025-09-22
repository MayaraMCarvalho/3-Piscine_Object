/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shovel.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:51:55 by macarval          #+#    #+#             */
/*   Updated: 2025/09/22 14:14:19 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Shovel.hpp"

// Constructor & Destructor ===================================================

Shovel::Shovel( void ) : ATool(0, NULL)
{
	std::cout << GREEN << "Shovel🛠️  created!" << RESET << std::endl;
}

Shovel::~Shovel( void )
{
	// if (_userWorker)
	// 	_userWorker->takenTool(*this);
	std::cout << RED << "Shovel🛠️  destroyed!" << RESET << std::endl;
}

Shovel::Shovel( Shovel const &copy ) : ATool (copy)
{
	std::cout << YELLOW << "Shovel🛠️  copied!" << RESET << std::endl;
}

// Operators ==================================================================
Shovel& Shovel::operator=( Shovel const &other )
{
	if (this != &other)
	{
		ATool::operator=(other);
		std::cout << BLUE << "Shovel🛠️  assigned!" << RESET << std::endl;
	}
	return *this;
}

// Getters ====================================================================

// Setters ====================================================================

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
