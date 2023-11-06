#include  <iostream>
#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap A("Alpha");
	ClapTrap B("Beta");

	A.attack("B");
	B.takeDamage(10);

	B.attack("Alpha");
	A.takeDamage(30);
	B.beRepaired(3);

	A.attack("B");
	B.takeDamage(10);

	ClapTrap C("Charlie");
	ClapTrap D("Delta");

	D = C;

	return 0;
}
