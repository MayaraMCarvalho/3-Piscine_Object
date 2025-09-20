/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:51:42 by macarval          #+#    #+#             */
/*   Updated: 2025/09/19 22:11:35 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKER_HPP
# define WORKER_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <typeinfo>

# include "Colors.hpp"
# include "Position.hpp"
# include "Statistic.hpp"
# include "ATool.hpp"
# include "Shovel.hpp"
# include "Hammer.hpp"

class Worker
{
	private:
	// Attributes =============================================================
		Position			_coordonnee;
		Statistic			_stat;
		std::vector<ATool*>	_tools;

	// Methods ================================================================
		void	takenTool(ATool& tool);

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
		ATool* getTool(ATool *obj) const;

	// Setters ================================================================

	// Methods ================================================================
		void	giveTool(ATool& tool);
};

#endif
