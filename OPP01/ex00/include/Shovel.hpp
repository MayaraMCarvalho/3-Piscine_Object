/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shovel.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:51:42 by macarval          #+#    #+#             */
/*   Updated: 2024/09/19 23:24:05 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOVEL_HPP
# define SHOVEL_HPP

# include <iostream>
# include "Colors.hpp"

class Worker;

class Shovel
{
	private:
		int		_numberOfUses;
		Worker	*_userWorker;

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
		Worker* getWorker( void ) const;

	// Setters ================================================================
		void	attachWorker(Worker &worker);

	// Methods ================================================================
		void	use( void );


};

#endif
