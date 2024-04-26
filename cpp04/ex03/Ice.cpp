#include "Ice.hpp"

// Constructors and destructor
Ice::Ice(void) : AMateria("ice") {
	std::cout << "Ice constructed!" << std::endl;
	return ;
}
Ice::Ice(const Ice &source) : AMateria(source) {
	std::cout << "Ice copy constructed!" << std::endl;
	return ;
}
Ice::~Ice(void) {
	std::cout << "Ice destructed!" << std::endl;
	return ;
}

// Operator overloads
Ice	&Ice::operator=(const Ice &other) {
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

// Member functions
AMateria	*Ice::clone(void) const {
	return (new Ice(*this));
}
void Ice::use(ICharacter& target) {
	std::cout << GREEN << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
	return ;
}
