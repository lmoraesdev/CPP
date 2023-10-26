#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <iostream>


class Contact
{
private:
public:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string secret;
	std::string phoneNumber;
	Contact();
	~Contact();
	void	setName(const char *name);
	std::string	getName();
};

#endif
