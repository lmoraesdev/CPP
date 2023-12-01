#if !defined(CHARACTER_HPP)
# define CHARACTER_HPP

#include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character :public ICharacter
{
private:
	AMateria *inventory[4];
	std::string name;
protected:

public:
	Character(std::string name);
	Character(const Character &ref);
	Character	&operator=(Character const &ref);
	virtual ~Character();

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif
