#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanA {
private:
	std::string	_name;
	Weapon&		_weapon;

public:
	//parameter constructor
	HumanA(const std::string initialName, Weapon& initialWeapon);
	//destructor
	~HumanA();

	//attack method
	void	attack(void) const;
};

#endif
