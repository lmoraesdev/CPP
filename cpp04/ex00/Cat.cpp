#include "Cat.hpp"

Cat::Cat()
: Animal()
{
	this->type = "Cat";
	std::cout << "Cat constructor called for cat" << std::endl;
}

Cat::Cat(const Cat &ref)
: Animal()
{
	*this = ref;
	std::cout << "Cat contructor by copy" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Destructor of Cat " << " called" <<std::endl;
}

Cat		&Cat::operator=(Cat const &ref)
{
	std::cout << "Assignation with operator= called" <<std::endl;
	if (this != &ref)
	{
		*this = ref;
	}
	return *this;
}
void Cat::makeSound()const {
	std::cout << "miau" << std::endl;
}
