#include "Contact.hpp"

void	Contact::setName(const char *name){
	this->firstName = name;
}

std::string	Contact::getName(){
	return this->firstName;
}

Contact::Contact()
{
}

Contact::~Contact()
{

}
