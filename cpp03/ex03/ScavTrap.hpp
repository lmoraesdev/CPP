#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	// Default constructor
	ScavTrap(void);
	// Constructor
	ScavTrap(std::string &name);
	// Copy constructor
	ScavTrap(const ScavTrap &source);
	// Destructor
	~ScavTrap(void);
	// Operator
	ScavTrap	&operator=(const ScavTrap &source);
	// Member functions
	void	attack(std::string const &target);
	void	guardGate(void);
};

#endif
