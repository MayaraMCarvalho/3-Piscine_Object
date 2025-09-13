#ifndef HAMMER_HPP
# define HAMMER_HPP

# include <iostream>

# include "Colors.hpp"
# include "ATool.hpp"

class Hammer : public ATool
{
	private:

	// Attributes =============================================================

	public:
	// Constructor & Destructor ===============================================
		Hammer( void );
		~Hammer( void );

	// ========================================================================
		Hammer( Hammer const &copy );

	// Operators ==============================================================
		Hammer& operator=( Hammer const &other );

	// Getters ================================================================

	// Setters ================================================================

	// Methods ================================================================
	void	use( void );

	// Exceptions =============================================================

};

#endif
