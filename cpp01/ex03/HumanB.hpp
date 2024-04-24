#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanB {
private:
	std::string		_name;
	const Weapon	*_weapon;

public:
	//parameter constructor
	HumanB(const std::string initialName);
	//destructor
	~HumanB();

	//attack method
	void	setWeapon(const Weapon& newWeapon);
	void	attack(void) const;
};

#endif
