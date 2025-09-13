/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:51:55 by macarval          #+#    #+#             */
/*   Updated: 2025/09/12 21:33:20 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Worker.hpp"

// Constructor & Destructor ===================================================

Worker::Worker(Position const &pos, Statistic const &stat)
	: _coordonnee(pos), _stat(stat), _tools()
{
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
ATool* Worker::getTool(ATool* obj) const
{
	for (std::vector<ATool*>::const_iterator it = this->_tools.begin();
			it != this->_tools.end(); ++it)
	{
		if (typeid(**it) == typeid(*obj))
			return (*it);
	}
	return (NULL);
}

// Setters ====================================================================

// Methods ====================================================================
void	Worker::giveTool(ATool& tool)
{
	Worker *userWorker = tool.getWorker();

	if (userWorker != NULL)
		userWorker->takenTool(tool);

	this->_tools.push_back(&tool);
	tool.attachWorker(*this);

	std::string name = typeid(tool).name();
	std::cout << BLUE << "Worker👷 received a "<< name.substr(1)
				<< "🛠️ !" << RESET << std::endl;
}

void	Worker::takenTool(ATool& tool)
{
	for (std::vector<ATool*>::iterator it = this->_tools.begin();
			it != this->_tools.end(); ++it)
	{
		if (*it == &tool)
		{
			this->_tools.erase(it);
			std::string name = typeid(tool).name();
			std::cout << YELLOW << name.substr(1) << "🛠️  taken away!"
					<< RESET << std::endl;
			return ;
		}
	}
}

// Exceptions =================================================================
