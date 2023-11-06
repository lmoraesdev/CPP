#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string const &name): ClapTrap(name)
{
	this->_energy = 50;
	this->_attack = 20;
	this->_hit_damage = 100;
	std::cout << "ScavTrap constructor called for "<< name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ref): ClapTrap()
{
	*this = ref;
	std::cout << "ScavTrap contructor by copy" << std::endl;
}


ScavTrap::~ScavTrap()
{
	std::cout << "Destructor of ScavTrap " << this->_name << " called" <<std::endl;
}

ScavTrap		&ScavTrap::operator=(ScavTrap const &ref)
{
	if (this != &ref)
		ClapTrap::operator=(ref);
	return *this;
}

void ScavTrap::guardGate()const {
	std::cout << "ScavTrap " << this->_name << " in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target){
	if (this->_energy >= 1){
		std::cout << "ScavTrap " << this->_name;
		std::cout << " attacks " << target;
		std::cout << " causing " << this->_attack << " points of damage" << std::endl;
	} else {
		std::cout << "ScavTrap " << this->_name;
		std::cout << "it's out of energy" << this->_name;
	}

}
