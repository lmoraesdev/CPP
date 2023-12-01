#include "Character.hpp"

Character::Character(std::string name)
{
	std::cout << "Character constructor called" << std::endl;
	this->name = name;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = 0;
}

Character::Character(const Character &ref)
{
	for (int i = 0; i < 4; i++){
		if (this->inventory[i])
			delete this->inventory[i];
	}
	this->name = ref.getName();
	for (int i = 0; i < 4; i++)
		this->inventory[i] = ref.inventory[i];
	std::cout << "Character contructor by copy" << std::endl;
}


Character::~Character()
{
	for (int i = 0; i < 4; i++){
		if (this->inventory[i])
			delete this->inventory[i];
	}
	std::cout << "Destructor of Character " << " called" <<std::endl;
}

Character		&Character::operator=(Character const &ref)
{
	std::cout << "Assignation with operator= called" <<std::endl;
	if (this != &ref)
	{
		for (int i = 0; i < 4; i++){
			if (this->inventory[i])
				delete this->inventory[i];
		}
		this->name = ref.getName();
		for (int i = 0; i < 4; i++)
			this->inventory[i] = ref.inventory[i];
	}
	return *this;
}

std::string const & Character::getName() const{
	return (this->name);
}

void Character::equip(AMateria* m){
	for (int i = 0; i < 4; i++){
		if (this->inventory[i] == 0){
			this->inventory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx){
	if (idx >= 0 && idx <= 3)
		this->inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target){
	if (idx >= 0 && idx <= 3)
		this->inventory[idx]->use(target);
}
