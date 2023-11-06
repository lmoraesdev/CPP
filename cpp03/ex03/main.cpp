#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int	main( void )
{

	DiamondTrap D("Diamond");

	D.attack("Bad_boy");
	// D.takeDamage(10);

	D.guardGate();
	D.highFivesGuys();

	D.whoAmI();
	return 0;
}
