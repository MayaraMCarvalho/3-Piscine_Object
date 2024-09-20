/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:51:42 by macarval          #+#    #+#             */
/*   Updated: 2024/09/19 20:23:03 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKER_HPP
# define WORKER_HPP

# include <iostream>

# include "Colors.hpp"
# include "Position.hpp"
# include "Statistic.hpp"
# include "Shovel.hpp"


class Worker
{
	private:
		Position	coordonnee;
		Statistic	stat;
		Shovel		*shovel;

	public:
	// Constructor & Destructor ===============================================
		Worker(Position const &pos, Statistic const &stat);
		~Worker( void );
	// Exceptions =============================================================

	// ========================================================================
		Worker( Worker const &copy );

	// Operators ==============================================================
		Worker& operator=( Worker const &other );
		friend std::ostream& operator<<(std::ostream& p_os, const Worker& p_worker);

	// Getters ================================================================

	// Setters ================================================================

	// Methods ================================================================
		void	giveShovel(Shovel& shovel);
		void	takenShovel( void );


};

#endif
