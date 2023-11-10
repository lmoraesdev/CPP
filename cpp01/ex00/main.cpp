#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

/**
 * This C++ code creates a Zombie object, creates a random zombie, announces the
 * name of the created zombie, and then deletes the created zombie object.
 *
 * @return The main function is returning 0.
 */
int	main(void){
	Zombie *zombie = newZombie("Clariosvaldo");
	randomChump("cladinho");
	zombie->announce();
	delete zombie;
	return (0);
}
