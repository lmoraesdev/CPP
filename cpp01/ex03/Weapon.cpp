#include "Weapon.hpp"

// Default constructor
Weapon::Weapon() {
	return ;
}

// Default constructor
Weapon::Weapon(const std::string initialType) {
	_type = initialType;
	return ;
}

// Destructor
Weapon::~Weapon() {
	return ;
}

// Setters
void	Weapon::setType(const std::string newType) {
	_type = newType;
	return ;
}

// Getters
const std::string&	Weapon::getType(void) const {
	return (_type);
}
