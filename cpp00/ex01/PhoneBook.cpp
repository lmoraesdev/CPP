#include "PhoneBook.hpp"

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

void	PhoneBook::showInfo(int index){
	std::cout << "First Name: " << this->contact[index].firstName << std::endl;
	std::cout << "Last Name: " << this->contact[index].lastName << std::endl;
	std::cout << "Nickname: " << this->contact[index].nickName << std::endl;
	std::cout << "Darkest Secret: " << this->contact[index].secret << std::endl;
	std::cout << "Phone Number: " << this->contact[index].phoneNumber << std::endl;
}

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

void PhoneBook::searchContact(int index){
	if (index >= 0 && index <= 7)
		this->drawLine(this->contact[index], index);
}

PhoneBook::PhoneBook()
{
	this->is_open = 1;
	this->size = 0;
	this->index = 0;
}

PhoneBook::~PhoneBook()
{
}
