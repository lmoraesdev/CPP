#if !defined(IMATERIASOURCE_HPP)
# define IMATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"

class IMateriaSource
{
protected:
public:
	IMateriaSource();
	IMateriaSource(const IMateriaSource &ref);
	IMateriaSource	&operator=(IMateriaSource const &ref);
	virtual ~IMateriaSource();
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;

};

#endif
