#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called for "<< name << std::endl;
}

Brain::Brain(const Brain &ref)
{
	*this = ref;
	std::cout << "Brain contructor by copy" << std::endl;
}


Brain::~Brain()
{
	std::cout << "Destructor of Brain " << " called" <<std::endl;
}

Brain		&Brain::operator=(Brain const &ref)
{
	std::cout << "Assignation with operator= called" <<std::endl;
	if (this != &ref)
		*this = ref;
	return *this;
}
