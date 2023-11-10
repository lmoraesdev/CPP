#include "HumanA.hpp"

/**
 * The HumanA class constructor initializes a HumanA object with a name and a
 * reference to a Weapon object, and the attack function prints out the name of the
 * human and the type of weapon they are using.
 *
 * @param name A string representing the name of the human.
 * @param weapon A reference to an object of type Weapon.
 */
HumanA::HumanA(const std::string name, Weapon &weapon)
: weapon(weapon)
{
	this->name = name;
}

/**
 * The function "attack" prints out the name of the human and the type of weapon
 * they are using.
 */
HumanA::~HumanA()
{
}

/**
 * The function "attack" prints out the name of the human and the type of weapon
 * they are using.
 */
void	HumanA::attack(void){
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
