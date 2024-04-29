#include "ScavTrap.hpp"

int	main(void)
{
	std::string scav_name = "Scavy";
	std::string scav_copy = "ScavyCopy";

	std::cout << std::endl << GREEN << "----- Constructor calls -----" << RESET << std::endl;
	ScavTrap scavy(scav_name);

	std::cout << std::endl << GREEN << "----- Inherited Member function calls -----" << RESET << std::endl;
	scavy.takeDamage(10);
	scavy.beRepaired(10);

	std::cout << std::endl << GREEN << "----- Modified Member function calls -----" << RESET << std::endl;
	scavy.attack("some other enemy");
	scavy.guardGate();

	std::cout << std::endl << GREEN << "----- Operator overloads -----" << RESET << std::endl;
	ScavTrap scavy2 = scavy;
	scavy2.attack("another enemy");

	std::cout << std::endl << GREEN << "----- Copy constructor -----" << RESET << std::endl;
	ScavTrap scavy3(scavy2);
	scavy3.attack("one more enemy");

	std::cout << std::endl << GREEN << "----- Polymorphism -----" << RESET << std::endl;
	ClapTrap *scavy4 = new ScavTrap(scav_copy);
	scavy4->attack("yet another enemy");

	std::cout << std::endl << GREEN << "----- Destructor calls -----" << RESET << std::endl;
	delete scavy4;
	return (0);
}
