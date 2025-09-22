/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:51:55 by macarval          #+#    #+#             */
/*   Updated: 2025/09/22 14:27:58 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Worker.hpp"
#include "Workshop.hpp"

// Constructor & Destructor ===================================================

Worker::Worker(Position const &pos, Statistic const &stat)
	: _coordonnee(pos), _stat(stat), _tools()
{
	std::cout << GREEN << "Worker👷 created!" << RESET << std::endl;
}

Worker::~Worker( void )
{
	for (std::vector<ATool*>::iterator it = this->_tools.begin();
			it != this->_tools.end(); ++it)
	{
		(*it)->detachWorker();
	}

	for (std::vector<Workshop*>::iterator it = this->_works.begin();
		it != this->_works.end(); ++it)
	{
		(*it)->removeWorker(this);
	}

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
	void	Worker::addWork(Workshop& work)
	{
		this->_works.push_back(&work);
	}

	void	Worker::removeWork(Workshop *work)
	{
		for (std::vector<Workshop*>::iterator it = this->_works.begin();
			it != this->_works.end(); ++it)
		{
			if (*it == work)
			{
				this->_works.erase(it);
				return ;
			}
		}
	}

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

void	Worker::work(void)
{
	if (!this->_works.empty())
		std::cout << BYELLOW << "Working...☀️" << RESET << std::endl;
	else
		std::cout << RED << "Worker does not belong to any workshop" << RESET << std::endl;
}
// Exceptions =================================================================
