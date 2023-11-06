#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
: _name(name), _attack(0), _energy(10), _hit_damage(10)
{
	std::cout << "Constructor called for ClapTrap(" << name << ")" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &ref)
: _name(ref._name), _attack(ref._attack), _energy(ref._energy), _hit_damage(ref._hit_damage)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor of ClapTrap " << this->_name << " called" << std::endl;
}

ClapTrap		&ClapTrap::operator=(ClapTrap const & ref)
{
	std::cout << "Assignation with operator= called" <<std::endl;
	if (this != &ref)
	{
		this->_name = ref._name;
		this->_hit_damage = ref._hit_damage;
		this->_energy = ref._energy;
		this->_attack = ref._attack;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target){
	if (this->_energy >= 1){
		std::cout << "ClapTrap " << this->_name;
		std::cout << " attacks " << target;
		std::cout << " causing " << this->_attack << " points of damage" << std::endl;
	} else {
		std::cout << "ClapTrap " << this->_name;
		std::cout << "it's out of energy" << this->_name;
	}

}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->_hit_damage > amount){
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage" << std::endl;
		this->_hit_damage -= amount;
	} else {
		std::cout << "ClapTrap " << this->_name;
		std::cout << " is died" << std::endl;
		this->_hit_damage = 0;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_energy >= 1){
		std::cout << "ClapTrap " << this->_name;
		std::cout << "repaired hit in " << amount << std::endl;
		this->_hit_damage += amount;
	}
	else {
		std::cout << "ClapTrap " << this->_name;
		std::cout << "it's out of energy" << this->_name;
	}
}
