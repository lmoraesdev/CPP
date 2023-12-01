#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure constructor called " << std::endl;
}

Cure::Cure(const Cure &ref) : AMateria("cure")
{

	std::cout << "Cure contructor by copy" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Destructor of Cure " << " called" <<std::endl;
}

Cure		&Cure::operator=(Cure const &ref)
{
	std::cout << "Assignation with operator= called" <<std::endl;
	if (this != &ref)
	{
		*this = ref;
	}
	return *this;
}

Cure* Cure::clone() const{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target){
	std::cout << "heals "<< target.getName() <<"'s wounds" << std::endl;
}
