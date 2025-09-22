/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Workshop.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:51:42 by macarval          #+#    #+#             */
/*   Updated: 2025/09/22 15:58:19 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKSHOP_HPP
# define WORKSHOP_HPP

# define FALSE 0
# define TRUE 1

# include <iostream>
# include <vector>

# include "Colors.hpp"
# include "Worker.hpp"

class Workshop
{
	private:
	// Attributes =============================================================
		std::vector<Worker*>	_employees;

	// Getters ================================================================
		bool	contractWorker(Worker *worker);

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
		void	hireWorker(Worker& worker);
		void	fireWorker(Worker* worker);

		template<typename T>
		void	hireExpert(Worker *worker)
		{
			if (contractWorker(worker))
				return ;

			if (worker->findTool<T>())
			{
				this->_employees.push_back(worker);
				worker->addWork(*this);

				std::cout << GREEN
						<< "Expert👨‍🏭 hired by the Workshop🏢!"
						<< RESET << std::endl;
				return ;
			}

			std::cout << RED <<"This worker is not an expert!"
						<< RESET << std::endl;
		}

	// Methods ================================================================
		void	removeWorker(Worker* worker);
		void	executeWorkDay(void);

	// Exceptions =============================================================

};

#endif
