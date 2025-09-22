/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shovel.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:51:42 by macarval          #+#    #+#             */
/*   Updated: 2025/09/22 15:48:22 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOVEL_HPP
# define SHOVEL_HPP

# include <iostream>

# include "Colors.hpp"
# include "ATool.hpp"

class Worker;

class Shovel : public ATool
{
	public:
	// Constructor & Destructor ===============================================
		Shovel( void );
		~Shovel( void );
	// Exceptions =============================================================

	// ========================================================================
		Shovel( Shovel const &copy );

	// Operators ==============================================================
		Shovel& operator=( Shovel const &other );

	// Getters ================================================================

	// Setters ================================================================

	// Methods ================================================================
		virtual void	use( void );
};

#endif
