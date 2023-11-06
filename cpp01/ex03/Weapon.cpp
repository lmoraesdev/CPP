#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon()
{
}

const std::string &Weapon::getType(){
	return (this->type);
}

void	Weapon::setType(std::string new_type){
	this->type = new_type;
}
