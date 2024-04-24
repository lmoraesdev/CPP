#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "Attack from HumanA" << std::endl;
	std::cout << "------------------" << std::endl;
	std::cout << std::endl;


	std::cout << YELLOW;
	Weapon clubA = Weapon("crude spiked club");
	HumanA bob("Bob", clubA);
	bob.attack();
	clubA.setType("some other type of club");
	bob.attack();
	std::cout << RESET;


	std::cout << std::endl;
	std::cout << "Attack from HumanB" << std::endl;
	std::cout << "------------------" << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW;
	Weapon clubB = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(clubB);
	jim.attack();
	clubB.setType("some other type of club");
	jim.attack();
	std::cout << RESET;
	return (0);
}
