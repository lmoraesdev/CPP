#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main( void )
{
	ClapTrap A("Alpha");
	ScavTrap B("Beta");

	ScavTrap C(B);
	ScavTrap D;

	D = B;

	A.attack("Beta");
	B.takeDamage(0);

	B.attack("Alpha");
	A.takeDamage(20);
	B.beRepaired(30);

	B.guardGate();

	return 0;
}
