#include "Cat.hpp"

// Constructor and destructor
Cat::Cat(void) : Animal("Cat") {
	std::cout << "Cat constructed!" << std::endl;
	_brain = new Brain();
	return ;
}
Cat::Cat(const Cat& other) : Animal(other) {
	if (this == &other)
		return ;
	_type = other._type;
	_brain = new Brain(*other._brain);
	std::cout << "Cat copy constructed!" << std::endl;
	return ;
}
Cat::~Cat(void) {
	delete _brain;
	std::cout << "Cat destructed!" << std::endl;
	return ;
}

// Operator overloads
Cat	&Cat::operator=(const Cat& other) {
	if (this == &other)
		return (*this);
	_type = other._type;
	_brain = new Brain(*other._brain);
	return (*this);
}

// Member functions
void	Cat::makeSound(void) const {
	std::cout << "Cat says: \"Meow!\"" << std::endl;
	return ;
}
