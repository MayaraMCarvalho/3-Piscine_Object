#include "Workshop.hpp"

// Constructor & Destructor ===================================================
Workshop::Workshop( void ) : _employees()
{
	std::cout << GREEN << "Workshop🏢 created!\n" << RESET << std::endl;
}

Workshop::~Workshop( void )
{
	for (std::vector<Worker*>::const_iterator it = _employees.begin();
			it != _employees.end(); ++it)
	{
		(*it)->removeWork(this);
	}
	std::cout << RED << "Workshop💥 destroyed!\n" << RESET << std::endl;
}

Workshop::Workshop( Workshop const &copy ) : _employees(copy._employees)
{
	std::cout << YELLOW << "Workshop🏢 copied!" << RESET << std::endl;
}

// Operators ==================================================================
Workshop& Workshop::operator=( Workshop const &other )
{
	if (this != &other)
	{
		this->_employees = other._employees;
		std::cout << BLUE << "Workshop🏢 assigned!" << RESET << std::endl;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& p_os, const Workshop& p_workshop)
{
	std::vector<Worker*>::const_iterator it;

	std::cout << PURPLE << "\nWorkshop: " << RESET << std::endl;
	for (it = p_workshop._employees.begin();
		it != p_workshop._employees.end(); ++it)
	{
		p_os << **it;
	}

	return (p_os);
}

// Getters ====================================================================
bool Workshop::contractWorker(Worker *worker)
{
	for (std::vector<Worker*>::iterator it = this->_employees.begin();
		it != this->_employees.end(); ++it)
	{
		if (*it == worker)
		{
			std::cout << RED << "Worker👷 already has this Workshop🏢"
			 		<< RESET << std::endl;
			return TRUE;
		}
	}
	return FALSE;
}

// Setters ====================================================================
void Workshop::hireWorker(Worker& worker)
{
	if (contractWorker(&worker))
		return ;

	this->_employees.push_back(&worker);
	worker.addWork(*this);
	std::cout << BLUE << "Worker👷 hired by the Workshop🏢"
				<< RESET << std::endl;
}

void Workshop::fireWorker(Worker* worker)
{
	for (std::vector<Worker*>::iterator it = this->_employees.begin();
		it != this->_employees.end(); ++it)
	{
		if (*it == worker)
		{
			this->_employees.erase(it);
			std::cout << RED << "Worker👷 fired from this Workshop🏢"
			 		<< RESET << std::endl;
			return ;
		}
	}

	std::cout << YELLOW << "Worker👷 does not work in this Workshop🏢"
				<< RESET << std::endl;

}

// Methods ====================================================================
void Workshop::removeWorker(Worker* worker)
{
	for (std::vector<Worker*>::iterator it = this->_employees.begin();
		it != this->_employees.end(); ++it)
	{
		if (*it == worker)
		{
			this->_employees.erase(it);
			return ;
		}
	}
}

void Workshop::executeWorkDay(void)
{
	for (std::vector<Worker*>::iterator it = this->_employees.begin();
		it != this->_employees.end(); ++it)
		(*it)->work();
}

// Exceptions =================================================================
