#include "Dog.hpp"

Dog::Dog()
: Animal()
{
	this->type = "Dog";
	this->brain = new Brain;
	std::cout << "Dog constructor called for "<< std::endl;
}

Dog::Dog(const Dog &ref)
: Animal()
{
	*this = ref;
	std::cout << "Dog contructor by copy" << std::endl;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Destructor of Dog " << " called" <<std::endl;
}

Dog		&Dog::operator=(Dog const &ref)
{
	std::cout << "Assignation with operator= called" <<std::endl;
	if (this != &ref)
		*this = ref;
	return *this;
}
void Dog::makeSound()const {
	std::cout << "au au" << std::endl;
}
