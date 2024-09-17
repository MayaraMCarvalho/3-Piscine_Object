/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   *.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:51:55 by macarval          #+#    #+#             */
/*   Updated: 2024/09/17 16:51:58 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class.hpp"

// Constructor & Destructor ===================================================
Class::Class( void )
{
	std::cout << "Default constructor called" << std::endl;
}

Class::Class( Class const &copy )
{
	*this = copy;
	std::cout << "Copy constructor called" << std::endl;
}

Class::~Class( void )
{
	std::cout << "Destructor called" << std::endl;
}

// Operators ==================================================================
Class& Class::operator=( Class const &other )
{
	if (this != &other)
	{
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

// Getters ====================================================================

// Setters ====================================================================

// Methods ====================================================================

// Exceptions =================================================================
