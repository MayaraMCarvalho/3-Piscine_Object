#ifndef ATOOL_HPP
# define ATOOL_HPP

# include <iostream>

# include "Colors.hpp"

class Worker;

class ATool
{
	protected:
	// Attributes =============================================================
		int		_numberOfUses;
		Worker	*_userWorker;

	public:
	// Constructor & Destructor ===============================================
		ATool( void );
		ATool( int numberOfUses, Worker *userWorker );
		virtual ~ATool( void );

	// ========================================================================
		ATool( ATool const &copy );

	// Operators ==============================================================
		ATool& operator=( ATool const &other );

	// Getters ================================================================
		Worker* getWorker( void ) const;

	// Setters ================================================================
		void attachWorker (Worker &worker);

	// Methods ================================================================
		virtual void use( void ) = 0;

	// Exceptions =============================================================

};

#endif
