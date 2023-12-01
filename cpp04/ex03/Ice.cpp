#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice constructor called " << std::endl;
}

Ice::Ice(const Ice &ref) : AMateria("ice")
{
	// *this = ref;
	std::cout << "Ice contructor by copy" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Destructor of Ice " << " called" <<std::endl;
}

Ice		&Ice::operator=(Ice const &ref)
{
	std::cout << "Assignation with operator= called" <<std::endl;
	if (this != &ref)
		*this = ref;
	return *this;
}

Ice* Ice::clone() const{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target){
	std::cout << "shoots an ice bolt at "<< target.getName() << std::endl;
}
