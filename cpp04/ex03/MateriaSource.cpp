#include "MateriaSource.hpp"

// Constructors and destructor
MateriaSource::MateriaSource(void) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Default MateriaSource constructed!" << std::endl;
	return ;
}
MateriaSource::MateriaSource(const MateriaSource &source) {
	*this = source;
	std::cout << "MateriaSource copy constructed!" << std::endl;
	return ;
}
MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
	std::cout << "MateriaSource destructed!" << std::endl;
	return ;
}

// Operator overloads
MateriaSource	&MateriaSource::operator=(const MateriaSource &other) {
	if (this == &other)
		return (*this);
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
	for (int i = 0; i < 4; i++)
		_inventory[i] = other._inventory[i]->clone();
	return (*this);
}

// Member functions
void MateriaSource::learnMateria(AMateria* materia) {
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) {
			_inventory[i] = materia;
			return ;
		}
	}
	return ;
}
AMateria* MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] && _inventory[i]->getType() == type)
			return (_inventory[i]->clone());
	}
	return (NULL);
}
