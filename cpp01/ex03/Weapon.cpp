#include "Weapon.hpp"

/**
 * The Weapon constructor initializes the type of the weapon.
 *
 * @param type The type of the weapon. It is a string that represents the category
 * or classification of the weapon, such as "sword", "bow", "axe", etc.
 */
Weapon::Weapon(std::string type)
{
	this->type = type;
}

/**
 * The destructor for the Weapon class.
 */
Weapon::~Weapon()
{
}

/**
 * The function returns the type of a weapon.
 *
 * @return a constant reference to a std::string object.
 */
const std::string &Weapon::getType(){
	return (this->type);
}

/**
 * The function sets the type of a weapon.
 *
 * @param new_type The new type of the weapon that we want to set. It is of type
 * std::string.
 */
void	Weapon::setType(std::string new_type){
	this->type = new_type;
}
