#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
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
	// Operator overloads
	ScavTrap	&operator=(const ScavTrap &other);
	// Member functions
	void	attack(std::string const &target);
	void	guardGate(void);
};

#endif
