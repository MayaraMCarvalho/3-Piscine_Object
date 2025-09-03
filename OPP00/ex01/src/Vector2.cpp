/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:51:55 by macarval          #+#    #+#             */
/*   Updated: 2025/09/03 15:45:17 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector2.hpp"

// Constructor & Destructor ===================================================
Vector2::Vector2( void ) : _x(NAN), _y(NAN) {}

Vector2::Vector2(float x, float y) : _x(x), _y(y) {}

Vector2::Vector2( Vector2 const &copy ) { *this = copy; }

Vector2::~Vector2( void ) {}

// Operators ==================================================================
Vector2& Vector2::operator=( Vector2 const &other )
{
	if (this != &other)
	{
		this->_x = other._x;
		this->_y = other._y;
	}
	return *this;
}

// Getters ====================================================================
float Vector2::getX() const { return _x; }

float Vector2::getY() const { return _y; }

// Setters ====================================================================

// Methods ====================================================================

// Exceptions =================================================================
