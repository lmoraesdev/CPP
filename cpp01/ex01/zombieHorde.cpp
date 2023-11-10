#include "Zombie.hpp"

/**
 * The function "zombieHorde" creates an array of "N" Zombie objects and sets their
 * names to the given "name" parameter.
 *
 * @param N The parameter N represents the number of zombies in the zombie horde.
 * @param name The name parameter is a string that represents the name of the
 * zombie horde.
 *
 * @return a pointer to an array of Zombie objects.
 */
Zombie* zombieHorde(int N, std::string name){
	Zombie *zombie = new Zombie[N];

	for (int i = 0; i < N; i++){
		zombie[i].set_name(name);
	}
	return (zombie);
}
