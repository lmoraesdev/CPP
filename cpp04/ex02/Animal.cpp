#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor called for "<< name << std::endl;
}

Animal::Animal(const Animal &ref)
{
	*this = ref;
	std::cout << "Animal contructor by copy" << std::endl;
}


Animal::~Animal()
{
	std::cout << "Destructor of Animal " << " called" <<std::endl;
}

Animal		&Animal::operator=(Animal const &ref)
{
	std::cout << "Assignation with operator= called" <<std::endl;
	if (this != &ref)
	{
		*this = ref;
	}
	return *this;
}
