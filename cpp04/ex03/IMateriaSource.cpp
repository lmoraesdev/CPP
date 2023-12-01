#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource()
{
	std::cout << "IMateriaSource constructor called " << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource &ref)
{
	*this = ref;
	std::cout << "IMateriaSource contructor by copy" << std::endl;
}

IMateriaSource::~IMateriaSource()
{
	std::cout << "Destructor of IMateriaSource " << " called" <<std::endl;
}

IMateriaSource		&IMateriaSource::operator=(IMateriaSource const &ref)
{
	std::cout << "Assignation with operator= called" <<std::endl;
	if (this != &ref)
	{
		*this = ref;
	}
	return *this;
}
