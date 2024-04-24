#include "HumanA.hpp"

// Constructor and destructor
HumanA::HumanA(const std::string initialName, Weapon& initialWeapon)
	: _name(initialName), _weapon(initialWeapon){
	return ;
}

HumanA::~HumanA() {
	return ;
}

// Methods
void	HumanA::attack(void) const {
	std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
	return ;
}
