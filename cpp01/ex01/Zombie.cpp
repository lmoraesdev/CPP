#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << this->name << " say goodbye!" << std::endl;
}

void Zombie::announce(void){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string name){
	this->name = name;
}

Zombie* newZombie(std::string name){
	Zombie *new_zombie = new Zombie;
	new_zombie->set_name(name);
	return (new_zombie);
}
