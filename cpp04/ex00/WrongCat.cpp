#include "WrongCat.hpp"

// Constructors and destructor
WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor called!" << std::endl;
	return ;
}
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	*this = other;
	std::cout << "WrongCat copy constructor called!" << std::endl;
	return ;
}
WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called!" << std::endl;
	return ;
}

// Operator overloads
WrongCat	&WrongCat::operator=(const WrongCat &other) {
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}
