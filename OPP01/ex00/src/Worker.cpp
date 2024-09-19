/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:51:55 by macarval          #+#    #+#             */
/*   Updated: 2024/09/19 19:44:01 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Worker.hpp"

// Constructor & Destructor ===================================================

Worker::Worker(Position const &pos, Statistic const &stat)
	: coordonnee(pos), stat(stat)
{
	std::cout << GREEN << "Worker👷 created!" << RESET << std::endl;
}

Worker::~Worker( void )
{
	std::cout << RED << "Worker☠️  destroyed!" << RESET << std::endl;
}

Worker::Worker( Worker const &copy )
				: coordonnee(copy.coordonnee), stat(copy.stat)
{
	std::cout << YELLOW << "Worker👷 copied!" << RESET << std::endl;
}

// Operators ==================================================================
Worker& Worker::operator=( Worker const &other )
{
	if (this != &other)
	{
		this->coordonnee = other.coordonnee;
		this->stat = other.stat;
		std::cout << BLUE << "Worker👷 assigned!" << RESET << std::endl;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& p_os, const Worker& p_worker)
{
	p_os << BLUE << "\nWorker:\n" << p_worker.coordonnee << p_worker.stat
			<< RESET;

	return (p_os);
}
// Getters ====================================================================

// Setters ====================================================================

// Methods ====================================================================

// Exceptions =================================================================
