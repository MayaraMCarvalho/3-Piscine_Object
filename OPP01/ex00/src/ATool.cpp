#include "ATool.hpp"

// Constructor & Destructor ===================================================
ATool::ATool( void ) : _numberOfUses(0), _userWorker(NULL) {}

ATool::ATool( int numberOfUses, Worker *userWorker ) :
	_numberOfUses(numberOfUses), _userWorker(userWorker) {}

ATool::~ATool( void ) {}

ATool::ATool( ATool const &copy ) :
	_numberOfUses(copy._numberOfUses), _userWorker(copy._userWorker) {}

// Operators ==================================================================
ATool& ATool::operator=( ATool const &other )
{
	if (this != &other)
	{
		this->_numberOfUses = other._numberOfUses;
		this->_userWorker = other._userWorker;
	}
	return *this;
}

// Getters ====================================================================
Worker* ATool::getWorker( void ) const
{
	return _userWorker;
}

// Setters ====================================================================
void ATool::attachWorker(Worker &worker)
{
	this->_userWorker = &worker;
}

// Methods ====================================================================

// Exceptions =================================================================
