#include "Dog.hpp"

// Constructor and destructor
Dog::Dog(void) : Animal("Dog") {
	std::cout << "Dog constructed!" << std::endl;
	return ;
}
Dog::Dog(const Dog& other) : Animal(other) {
	*this = other;
	std::cout << "Dog copy constructed!" << std::endl;
	return ;
}
Dog::~Dog(void) {
	std::cout << "Dog destructed!" << std::endl;
	return ;
}

// Operator overloads
Dog	&Dog::operator=(const Dog& other) {
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

// Member functions
void	Dog::makeSound(void) const {
	std::cout << "Dog says: \"Woof!\"" << std::endl;
	return ;
}
