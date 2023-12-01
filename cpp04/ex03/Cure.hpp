#if !defined(CURE_HPP)
# define CURE_HPP

#include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
protected:

public:
	Cure();
	Cure(const Cure &ref);
	Cure	&operator=(Cure const &ref);
	virtual ~Cure();
	std::string const & getType() const; //Returns the materia type
	Cure* clone() const;
	void use(ICharacter& target);

};

#endif
