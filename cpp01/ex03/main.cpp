#include <string>
#include <iostream>

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"


/**
 * The main function creates instances of HumanA and HumanB, sets their weapons,
 * and calls their attack functions.
 *
 * @return The main function is returning an integer value of 0.
 */
int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}
