#include "PhoneBook.hpp"

/**
 * The addContact function adds a new contact to the PhoneBook by prompting the
 * user for various details such as first name, last name, nickname, darkest
 * secret, and phone number.
 */
void	PhoneBook::addContact(void){
	Contact newContact;
	if (this->index > 7)
		this->index = 0;
	this->contact[this->index] = newContact;
	while (!this->contact[this->index].firstName.size()){
		std::cout << "First Name: ";
		std::getline(std::cin, this->contact[this->index].firstName);
	}

	while (!this->contact[this->index].lastName.size()){
		std::cout << "Last Name: ";
		std::getline(std::cin, this->contact[this->index].lastName);
	}

	while (!this->contact[this->index].nickName.size()){
		std::cout << "Nickname: ";
		std::getline(std::cin, this->contact[this->index].nickName);
	}

	while (!this->contact[this->index].secret.size()){
		std::cout << "Darkest Secret: ";
		std::getline(std::cin, this->contact[this->index].secret);
	}

	while (!this->contact[this->index].phoneNumber.size()){
		std::cout << "Phone Number: ";
		std::getline(std::cin, this->contact[this->index].phoneNumber);
	}

	std::cout << "Done " << std::endl;
	this->index++;
	if (this->size < 8)
		this->size++;
}

/**
 * The function "drawLine" takes a Contact object and an index as parameters, and
 * prints the contact's information in a formatted line.
 *
 * @param contact The parameter "contact" is of type "Contact" and represents the
 * contact information for a person.
 * @param index The index parameter is an integer that represents the position of
 * the contact in the phone book.
 */
void	PhoneBook::drawLine(Contact contact, int index){
	Contact tmp = contact;

	if (tmp.firstName.length() > 10){
		tmp.firstName.erase(10, -1);
		tmp.firstName[9] = '.';
	}

	if (tmp.lastName.length() > 10){
		tmp.lastName.erase(10, -1);
		tmp.lastName[9] = '.';
	}

	if (tmp.nickName.length() > 10){
		tmp.nickName.erase(10, -1);
		tmp.nickName[9] = '.';
	}

	std::cout << std::setfill(' ') << std::setw(10) << index << "|";
	std::cout << std::setfill(' ') << std::setw(10) << tmp.firstName  << "|";
	std::cout << std::setfill(' ') << std::setw(10) << tmp.lastName  << "|";
	std::cout << std::setfill(' ') << std::setw(10) << tmp.nickName <<  "|" << std::endl;
}

/**
 * The function "showInfo" prints out the contact information for a given index in
 * the PhoneBook.
 *
 * @param index The parameter "index" is an integer that represents the index of
 * the contact in the phone book that you want to display the information for.
 */
void	PhoneBook::showInfo(int index){
	std::cout << "First Name: " << this->contact[index].firstName << std::endl;
	std::cout << "Last Name: " << this->contact[index].lastName << std::endl;
	std::cout << "Nickname: " << this->contact[index].nickName << std::endl;
	std::cout << "Darkest Secret: " << this->contact[index].secret << std::endl;
	std::cout << "Phone Number: " << this->contact[index].phoneNumber << std::endl;
}

/**
 * The function "showContacts" displays the contacts in the phone book and allows
 * the user to select a contact to view more information.
 *
 * @return The function does not have a return type, so it does not return
 * anything.
 */
void	PhoneBook::showContacts(void){
	std::string	buffer;
	int			index;

	for (int x = 0; x < 8 && x < this->size; x++){
		PhoneBook::drawLine(this->contact[x], x);
	}
	if (size > 0){
		while (!buffer.size()){
			std::cout << "Put index to see more infos: ";
			std::getline(std::cin, buffer);
		}
		for (int i = 0; buffer[i]; i++){
			if (!isdigit(buffer[i])){
				std::cout << "Invalid index" << std::endl;
				return ;
			}
		}
		index = atoi((const char *)buffer.c_str());
		if (0 <= index  && index <= 7 && index < size)
			PhoneBook::showInfo(index);
		else
			std::cout << "No such contact!" << std::endl;
	}
	else
		std::cout << "Empty contact list" << std::endl;
}

/**
 * The searchContact function in the PhoneBook class searches for a contact at a
 * given index and draws a line to display the contact information.
 *
 * @param index The index parameter is an integer that represents the position of
 * the contact in the phone book that we want to search for. It should be a value
 * between 0 and 7, inclusive.
 */
void PhoneBook::searchContact(int index){
	if (index >= 0 && index <= 7)
		this->drawLine(this->contact[index], index);
}

/**
 * The PhoneBook constructor initializes the is_open, size, and index variables.
 */
PhoneBook::PhoneBook()
{
	this->is_open = 1;
	this->size = 0;
	this->index = 0;
}

/**
 * The destructor for the PhoneBook class.
 */
PhoneBook::~PhoneBook()
{
}
