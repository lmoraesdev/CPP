#include "HumanB.hpp"

/**
 * The above function is a constructor for the HumanB class that takes a name
 * parameter and assigns it to the name member variable.
 *
 * @param name The parameter "name" is of type std::string and represents the name
 * of the HumanB object being created.
 */
HumanB::HumanB(const std::string name)
{
	this->name = name;
}

/**
 * The above function is a destructor for the HumanB class.
 */
HumanB::~HumanB()
{
}

/**
 * The function "attack" prints out the name of the human and the type of weapon
 * they are using.
 */
void	HumanB::attack(void){
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

/**
 * The function "setWeapon" sets the weapon of a HumanB object to the specified
 * weapon.
 *
 * @param weapon A reference to an object of type Weapon.
 */
void 	HumanB::setWeapon(Weapon &weapon){
	this->weapon = &weapon;
}
