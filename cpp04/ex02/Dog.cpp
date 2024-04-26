#include "Dog.hpp"

// Constructor and destructor
Dog::Dog(void) : AAnimal("Dog") {
	std::cout << "Dog constructed!" << std::endl;
	_brain = new Brain();
	return ;
}
Dog::Dog(const Dog& other) : AAnimal(other) {
	if (this == &other)
		return ;
	_type = other._type;
	_brain = new Brain(*other._brain);
	std::cout << "Dog copy constructed!" << std::endl;
	return ;
}
Dog::~Dog(void) {
	delete _brain;
	std::cout << "Dog destructed!" << std::endl;
	return ;
}

// Operator overloads
Dog	&Dog::operator=(const Dog& other) {
	if (this == &other)
		return (*this);
	_type = other._type;
	_brain = new Brain(*other._brain);
	return (*this);
}

// Member functions
void	Dog::makeSound(void) const {
	std::cout << "Dog says: \"Woof!\"" << std::endl;
	return ;
}
