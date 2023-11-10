#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

/**
 * The main function creates a horde of zombies and makes each zombie announce
 * itself before deleting the horde.
 *
 * @return The main function is returning 0.
 */
int	main(void){
	Zombie *horde = zombieHorde(5, "cleriton");
	for(int i = 0; i < 5; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
