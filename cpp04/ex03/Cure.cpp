#include "Cure.hpp"

// Constructors and destructor
Cure::Cure(void) : AMateria("cure") {
	std::cout << "Cure constructed!" << std::endl;
	return ;
}
Cure::Cure(const Cure &source) : AMateria(source) {
	std::cout << "Cure copy constructed!" << std::endl;
	return ;
}
Cure::~Cure(void) {
	std::cout << "Cure destructed!" << std::endl;
	return ;
}

// Operator overloads
Cure	&Cure::operator=(const Cure &other) {
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

// Member functions
AMateria	*Cure::clone(void) const {
	return (new Cure(*this));
}
void Cure::use(ICharacter& target) {
	std::cout << GREEN << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl;
	return ;
}
