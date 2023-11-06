#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int	main(void){
	Zombie *zombie = newZombie("Clariosvaldo");
	randomChump("cladinho");
	zombie->announce();
	delete zombie;
	return (0);
}
