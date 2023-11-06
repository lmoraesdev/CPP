#if !defined(SCAVTRAP_HPP)
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap(std::string const &name = "Default_Scav");
	ScavTrap(const ScavTrap &ref);
	ScavTrap	&operator=(ScavTrap const &rsh);
	~ScavTrap();
	void guardGate()const;
	void attack(const std::string& target);
};

#endif // SCAVTRAP_HPP
