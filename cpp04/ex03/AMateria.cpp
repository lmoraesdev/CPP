#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
	std::cout << "AMateria constructor called " << std::endl;
	this->type = type;
}

AMateria::AMateria(const AMateria &ref)
{
	*this = ref;
	std::cout << "AMateria contructor by copy" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "Destructor of AMateria " << " called" <<std::endl;
}

AMateria		&AMateria::operator=(AMateria const &ref)
{
	std::cout << "Assignation with operator= called" <<std::endl;
	if (this != &ref)
	{
		*this = ref;
	}
	return *this;
}

std::string const & AMateria::getType() const {
	return (this->type);
}

void AMateria::use(ICharacter& target){

}
