#if !defined(DIAMONDTRAP_HPP)
# define DIAMONDTRAP_HPP

# include <iostream>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string _name;
	unsigned int _hit_damage;
	unsigned int _energy;
	unsigned int _attack;
public:
	DiamondTrap(std::string const &name = "Default_Diamond");
	DiamondTrap(const DiamondTrap &ref);
	DiamondTrap	&operator=(DiamondTrap const &ref);
	~DiamondTrap();
	void attack(const std::string& target);
	void whoAmI()const ;

};

#endif // DIAMONDTRAP_HPP
