#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
protected:
	std::string _name;
	unsigned int _attack;
	unsigned int _energy;
	unsigned int _hit_damage;
public:
	ClapTrap(std::string const &name = "Default_ClapTrap");
	ClapTrap(ClapTrap const &ref);
	ClapTrap		&operator=(ClapTrap const & ref);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
