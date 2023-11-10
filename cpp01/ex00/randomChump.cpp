#include "Zombie.hpp"

/**
 * The function "randomChump" creates a Zombie object with the given name and calls
 * the "announce" function on it.
 *
 * @param name The name of the zombie that will be created.
 */
void randomChump(std::string name){
	Zombie zombie(name);
	zombie.announce();
}
