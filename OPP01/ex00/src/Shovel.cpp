/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shovel.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:51:55 by macarval          #+#    #+#             */
/*   Updated: 2024/09/19 19:50:38 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Shovel.hpp"

// Constructor & Destructor ===================================================

Shovel::Shovel( void )
{
	std::cout << GREEN << "Worker👷 created!" << RESET << std::endl;
}

Shovel::~Shovel( void ) {}

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

// Setters ====================================================================

// Methods ====================================================================

// Exceptions =================================================================
