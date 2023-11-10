#include "Zombie.hpp"

/**
 * The Zombie constructor initializes a Zombie object with the given name.
 *
 * @param name A string representing the name of the zombie.
 */
Zombie::Zombie(std::string name)
{
	this->name = name;
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
