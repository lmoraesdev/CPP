#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>
# include "AMateria.hpp"

/*
Description: The IMateriaSource interface class is the base class for the
MateriaSource class. It has a virtual destructor and a pure virtual function
called createMateria that will be implemented by the MateriaSource class. The
createMateria function will receive a string and return a pointer to an AMateria
object.
*/

class IMateriaSource
{
public:
	// Constructors and destructor
	virtual ~IMateriaSource(void) {};
	// Member functions
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
