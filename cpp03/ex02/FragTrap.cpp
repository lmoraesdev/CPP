#include "FragTrap.hpp"

// Constructor and destructor
FragTrap::FragTrap(void) : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Default FragTrap constructed!" << std::endl;
	return ;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " constructed!" << std::endl;
	return ;
}
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	*this = other;
	std::cout << "FragTrap " << _name << " copy constructed!" << std::endl;
	return ;
}
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << _name << " destructed!" << std::endl;
	return ;
}

// Operator overloads
FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	if (this == &other)
		return (*this);
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

// Member functions
void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " says: \"High five, guys!\"" << std::endl;
	return ;
}
