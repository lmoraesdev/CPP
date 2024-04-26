#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

/*
Description: The Cure class is a concrete class that inherits from the AMateria
class. It has a type, which is the name of the spell, and a use function that
will be implemented by the concrete classes. The use function will receive a
target as parameter, which will be the character that will be the target of the
spell.
*/

class Cure : public AMateria
{
public:
	// Constructors and destructor
	Cure(void);
	Cure(const Cure &source);
	virtual ~Cure(void);

	// Operator overloads
	Cure	&operator=(const Cure &other);

	// Member functions
	AMateria* clone(void) const;
	void use(ICharacter& target);
};

#endif
