#if !defined(ICE_HPP)
# define ICE_HPP

#include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
protected:
public:
	Ice();
	Ice(const Ice &ref);
	Ice	&operator=(Ice const &ref);
	virtual ~Ice();
	virtual Ice* clone() const;
	virtual void use(ICharacter& target);
};

#endif
