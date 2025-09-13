#include "Hammer.hpp"

// Constructor & Destructor ===================================================
Hammer::Hammer( void ) : ATool(0, NULL)
{
	std::cout << GREEN << "Hammer🔨 created!" << RESET << std::endl;
}

Hammer::~Hammer( void )
{
	std::cout << RED << "Hammer🔨 destroyed!" << RESET << std::endl;
}

Hammer::Hammer( Hammer const &copy ) : ATool(copy)
{
	*this = copy;
	std::cout << YELLOW << "Hammer🔨 copied!" << RESET << std::endl;
}

// Operators ==================================================================
Hammer& Hammer::operator=( Hammer const &other )
{
	if (this != &other)
	{
		ATool::operator=(other);
		std::cout << BLUE << "Hammer🔨 assigned!" << RESET << std::endl;
	}
	return *this;
}

// Getters ====================================================================

// Setters ====================================================================

// Methods ====================================================================
void	Hammer::use( void )
{
	this->_numberOfUses++;

	std::cout << PURPLE << "Hammer🔨 used📍 ";
	if (_numberOfUses == 1)
		std::cout << "once!";
	else
		std::cout << _numberOfUses << " times!";
	std::cout << RESET << std::endl;
}

// Exceptions =================================================================
