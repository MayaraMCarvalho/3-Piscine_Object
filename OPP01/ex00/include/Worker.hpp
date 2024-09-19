/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:51:42 by macarval          #+#    #+#             */
/*   Updated: 2024/09/19 19:45:11 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKER_HPP
# define WORKER_HPP

# include <iostream>

# include "Position.hpp"
# include "Statistic.hpp"
# include "Colors.hpp"

class Worker
{
	private:
		Position	coordonnee;
		Statistic	stat;

	public:
	// Constructor & Destructor ===============================================
		Worker(Position const &pos, Statistic const &stat);
		~Worker( void );
	// Exceptions =============================================================

	// ========================================================================
		Worker( Worker const &copy );

	// Operators ==============================================================
		Worker& operator=( Worker const &other );

	// Getters ================================================================

	// Setters ================================================================

	// Methods ================================================================
	friend std::ostream& operator<<(std::ostream& p_os, const Worker& p_worker);

};

#endif
