#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

// FragTrap class
class FragTrap : public ClapTrap
{
	public:
		// Default constructor
		FragTrap(void);
		// Class constructor
		FragTrap(std::string name);
		// Copy constructor
		FragTrap(const FragTrap& other);
		// Destructor
		~FragTrap(void);
		// Operator overloads
		FragTrap	&operator=(const FragTrap &other);
		// Member functions
		void	highFivesGuys(void);
};

#endif
