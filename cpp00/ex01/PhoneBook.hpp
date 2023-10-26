#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contact[8];
	int		index;
	int		size;
public:
	int		is_open;
	PhoneBook();
	~PhoneBook();
	void	addContact();
	void	searchContact(int index);
	void	showContacts(void);
	void	showInfo(int index);
	void	drawLine(Contact contact, int index);
};

#endif
