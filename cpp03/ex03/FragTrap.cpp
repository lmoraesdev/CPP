#include "FragTrap.hpp"

FragTrap::FragTrap(std::string const &name): ClapTrap(name)
{
	this->_energy = 100;
	this->_attack = 30;
	this->_hit_damage = 100;
	std::cout << "FragTrap constructor called for "<< name << std::endl;
}

FragTrap::FragTrap(const FragTrap &ref): ClapTrap()
{
	*this = ref;
	std::cout << "FragTrap contructor by copy" << std::endl;
}


FragTrap::~FragTrap()
{
	std::cout << "Destructor of FragTrap " << this->_name << " called" <<std::endl;
}

FragTrap		&FragTrap::operator=(FragTrap const &ref)
{
	if (this != &ref)
		ClapTrap::operator=(ref);
	return *this;
}

void FragTrap::highFivesGuys(){
	std::cout << "FragTrap "<< this->_name <<" : High Fives Guys !" << std::endl;
}
