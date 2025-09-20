/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Workshop.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:51:42 by macarval          #+#    #+#             */
/*   Updated: 2025/09/19 22:11:50 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKSHOP_HPP
# define WORKSHOP_HPP

# include <iostream>
# include <vector>

# include "Colors.hpp"
# include "Worker.hpp"

class Workshop
{
	private:
	// Attributes =============================================================
		std::vector<Worker*>	_employees;

	public:
	// Constructor & Destructor ===============================================
		Workshop( void );
		~Workshop( void );

	// ========================================================================
		Workshop( Workshop const &copy );

	// Operators ==============================================================
		Workshop& operator=( Workshop const &other );
		friend std::ostream& operator<<(std::ostream& p_os, const Workshop& p_workshop);

	// Getters ================================================================

	// Setters ================================================================
		void registerWorker(Worker* worker);

	// Methods ================================================================

	// Exceptions =============================================================

};

#endif
