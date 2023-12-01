#if !defined(ICHARACTER_HPP)
# define ICHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"

class ICharacter
{
protected:

public:
	ICharacter();
	ICharacter(const ICharacter &ref);
	ICharacter	&operator=(ICharacter const &ref);
	virtual ~ICharacter();
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

#endif
