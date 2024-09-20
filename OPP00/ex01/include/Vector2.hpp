/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:51:42 by macarval          #+#    #+#             */
/*   Updated: 2024/09/19 23:21:19 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_HPP
# define VECTOR2_HPP

# include <iostream>

# include <cmath>

class Vector2
{
	private:
		float _x;
		float _y;

	public:
	// Constructor & Destructor ===============================================
		Vector2( void );
		Vector2(float x, float y);
		~Vector2( void );
	// Exceptions =============================================================

	// ========================================================================
		Vector2( Vector2 const &copy );

	// Operators ==============================================================
		Vector2& operator=( Vector2 const &other );

	// Getters ================================================================
		float	getX() const;
		float	getY() const;

	// Setters ================================================================

	// Methods ================================================================

};

#endif
