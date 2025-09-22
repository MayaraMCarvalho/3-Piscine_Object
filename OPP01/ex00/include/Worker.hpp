/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:51:42 by macarval          #+#    #+#             */
/*   Updated: 2025/09/22 15:55:07 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKER_HPP
# define WORKER_HPP

# define FALSE 0
# define TRUE 1

# include <iostream>
# include <vector>
# include <algorithm>
# include <typeinfo>

# include "Colors.hpp"
# include "Position.hpp"
# include "Statistic.hpp"
# include "ATool.hpp"

class Worker;
class Workshop;

class Worker
{
	private:
	// Attributes =============================================================
		Position				_coordonnee;
		Statistic				_stat;
		std::vector<ATool*>		_tools;
		std::vector<Workshop*>	_works;

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
		template <typename T>
		T*	getTool(void) const
		{
			for (std::vector<ATool*>::const_iterator it = this->_tools.begin();
					it != this->_tools.end(); ++it)
			{
				T* tool = dynamic_cast<T*>(*it);
				if (tool)
				{
					std::string name = typeid(tool).name();
					std::cout << YELLOW << name.substr(2)
							<< "🛠️  found and assigned!" << RESET << std::endl;
					return (tool);
				}
			}

			std::string name = typeid(T).name();
			std::cout << RED << name.substr(1)
							<< "🛠️  not found!" << RESET << std::endl;
			return (NULL);
		}

		template <typename T>
		bool	findTool(void) const
		{
			for (std::vector<ATool*>::const_iterator it = this->_tools.begin();
					it != this->_tools.end(); ++it)
			{
				T* tool = dynamic_cast<T*>(*it);
				if (tool)
					return (TRUE);
			}
			return (FALSE);
		}

	// Setters ================================================================
		void	addWork(Workshop& work);
		void	removeWork(Workshop *work);

	// Methods ================================================================
		void	giveTool(ATool& tool);
		void	takenTool(ATool& tool);
		void	work(void);
};

#endif
