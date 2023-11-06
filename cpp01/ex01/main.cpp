#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int	main(void){
	Zombie *horde = zombieHorde(5, "cleriton");
	for(int i = 0; i < 5; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
