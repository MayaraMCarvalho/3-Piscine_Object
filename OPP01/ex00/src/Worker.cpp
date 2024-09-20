/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:51:55 by macarval          #+#    #+#             */
/*   Updated: 2024/09/19 23:23:09 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Worker.hpp"

// Constructor & Destructor ===================================================

Worker::Worker(Position const &pos, Statistic const &stat)
	: _coordonnee(pos), _stat(stat)
{
	this->_shovel = NULL;
	std::cout << GREEN << "Worker👷 created!" << RESET << std::endl;
}

Worker::~Worker( void )
{
	std::cout << RED << "Worker☠️  destroyed!" << RESET << std::endl;
}

Worker::Worker( Worker const &copy )
				: _coordonnee(copy._coordonnee), _stat(copy._stat)
{
	std::cout << YELLOW << "Worker👷 copied!" << RESET << std::endl;
}

// Operators ==================================================================
Worker& Worker::operator=( Worker const &other )
{
	if (this != &other)
	{
		this->_coordonnee = other._coordonnee;
		this->_stat = other._stat;
		std::cout << BLUE << "Worker👷 assigned!" << RESET << std::endl;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& p_os, const Worker& p_worker)
{
	p_os << BLUE << "\nWorker:\n" << p_worker._coordonnee << p_worker._stat
			<< RESET;

	return (p_os);
}
// Getters ====================================================================

// Setters ====================================================================

// Methods ====================================================================
void	Worker::giveShovel(Shovel& shovel)
{
	Worker *userWorker = shovel.getWorker();

	if (userWorker != NULL)
		userWorker->takenShovel();

	this->_shovel = &shovel;
	shovel.attachWorker(*this);
	std::cout << BLUE << "Worker👷 received a shovel🛠️ !" << RESET << std::endl;
}

void	Worker::takenShovel( void )
{
	this->_shovel = NULL;
	std::cout << YELLOW << "Shovel🛠️  taken away!" << RESET << std::endl;
}

// Exceptions =================================================================
