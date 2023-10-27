#include "Contact.hpp"

/**
 * The function sets the first name of a contact.
 *
 * @param name A pointer to a character array representing the name of the contact.
 */
void	Contact::setName(const char *name){
	this->firstName = name;
}

/**
 * The function returns the first name of a contact.
 *
 * @return a string, which is the value of the member variable "firstName" of the
 * Contact object.
 */
std::string	Contact::getName(){
	return this->firstName;
}

/**
 * The Contact constructor is defined.
 */
Contact::Contact()
{
}

/**
 * The above code snippet is the destructor definition for the Contact class in
 * C++.
 */
Contact::~Contact()
{

}
