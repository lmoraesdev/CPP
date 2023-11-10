#include "Zombie.hpp"

/**
 * The above function is the constructor for the Zombie class.
 */
Zombie::Zombie()
{
}

/**
 * The destructor for the Zombie class prints a farewell message with the name of
 * the zombie.
 */
Zombie::~Zombie()
{
	std::cout << this->name << " say goodbye!" << std::endl;
}

/**
 * The function "announce" prints a message indicating that the zombie is saying
 * "BraiiiiiiinnnzzzZ...".
 */
void Zombie::announce(void){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/**
 * The function "newZombie" creates a new Zombie object with the given name and
 * returns a pointer to it.
 *
 * @param name A string representing the name of the zombie.
 */
void	Zombie::set_name(std::string name){
	this->name = name;
}

/**
 * The function "newZombie" creates a new Zombie object with the given name and
 * returns a pointer to it.
 *
 * @param name A string representing the name of the zombie.
 *
 * @return a pointer to a Zombie object.
 */
Zombie* newZombie(std::string name){
	Zombie *new_zombie = new Zombie;
	new_zombie->set_name(name);
	return (new_zombie);
}
