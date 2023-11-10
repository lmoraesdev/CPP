#include "Zombie.hpp"

/**
 * The function "newZombie" creates a new Zombie object with the given name and
 * returns a pointer to it.
 *
 * @param name A string representing the name of the zombie.
 *
 * @return A pointer to a Zombie object.
 */
Zombie* newZombie(std::string name){
	Zombie *new_zombie = new Zombie(name);
	return (new_zombie);
}
