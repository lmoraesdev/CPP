#include "AAnimal.hpp"

// Constructors and destructor
AAnimal::AAnimal(void) : _type("") {
	std::cout << "Default abstract animal constructed!" << std::endl;
	return ;
}
AAnimal::AAnimal(std::string type) : _type(type) {
	std::cout << "Abstract animal of type " << _type << " constructed!" << std::endl;
	return ;
}
AAnimal::AAnimal(const AAnimal& other) {
	*this = other;
	std::cout << "Abstract animal of type " << _type << " copy constructed!" << std::endl;
	return ;
}
AAnimal::~AAnimal(void) {
	std::cout << "Abstract animal of type " << _type << " destructed!" << std::endl;
	return ;
}

// Operator overloads
AAnimal	&AAnimal::operator=(const AAnimal& other) {
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

// Member functions
std::string	AAnimal::getType(void) const {
	return (_type);
}
