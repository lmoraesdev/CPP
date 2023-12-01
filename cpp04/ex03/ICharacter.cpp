#include "ICharacter.hpp"

ICharacter::ICharacter()
{
	std::cout << "ICharacter constructor called" << std::endl;
}

ICharacter::ICharacter(const ICharacter &ref)
{
	*this = ref;
	std::cout << "ICharacter contructor by copy" << std::endl;
}


ICharacter::~ICharacter()
{
	std::cout << "Destructor of ICharacter " << " called" <<std::endl;
}

ICharacter		&ICharacter::operator=(ICharacter const &ref)
{
	std::cout << "Assignation with operator= called" <<std::endl;
	if (this != &ref)
	{
		*this = ref;
	}
	return *this;
}
