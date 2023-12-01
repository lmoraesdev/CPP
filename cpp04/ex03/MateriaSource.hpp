#if !defined(MATERIASOURCE_HPP)
# define MATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *inv[4];
protected:
public:
	MateriaSource();
	MateriaSource(const MateriaSource &ref);
	MateriaSource	&operator=(MateriaSource const &ref);
	~MateriaSource();
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);

};

#endif
