#include "HumanB.hpp"

// Constructor and destructor
HumanB::HumanB(const std::string initialName) : _name(initialName) {
	return ;
}

HumanB::~HumanB() {
	return ;
}

// Methods
void	HumanB::attack(void) const {
	std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
	return ;
}

void	HumanB::setWeapon(const Weapon& newWeapon) {
	_weapon = &newWeapon;
	return ;
}
