/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:51:55 by macarval          #+#    #+#             */
/*   Updated: 2024/09/19 14:07:11 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector2.hpp"

// Constructor & Destructor ===================================================
Vector2::Vector2( void ) : x(NAN), y(NAN) {}

Vector2::Vector2(float x, float y) : x(x), y(y) {}

Vector2::Vector2( Vector2 const &copy ) { *this = copy; }

Vector2::~Vector2( void ) {}

// Operators ==================================================================
Vector2& Vector2::operator=( Vector2 const &other )
{
	if (this != &other)
	{
		this->x = other.x;
		this->y = other.y;
	}
	return *this;
}

// Getters ====================================================================
float Vector2::getX() const { return x; }

float Vector2::getY() const { return y; }

// Setters ====================================================================

// Methods ====================================================================

// Exceptions =================================================================
