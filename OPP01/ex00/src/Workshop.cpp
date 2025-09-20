#include "Workshop.hpp"

// Constructor & Destructor ===================================================
Workshop::Workshop( void ) : _employees()
{
	std::cout << GREEN << "Workshop🏢 created!" << RESET << std::endl;
}

Workshop::~Workshop( void )
{
	std::cout << RED << "Workshop💥 destroyed!" << RESET << std::endl;
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

// Setters ====================================================================
void Workshop::registerWorker(Worker* worker)
{
	// incluir validação se worker já tiver sido adicionado.

	this->_employees.push_back(worker);
	std::cout << BLUE << "Worker👷 registered in the Workshop🏢"
				<< RESET << std::endl;
}

// Methods ====================================================================

// Exceptions =================================================================
