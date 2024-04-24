#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook {
	private:
		// Attributes
		static const int _MAX_CONTACTS = 8;
		Contact	_contacts[_MAX_CONTACTS];
		int		_index;
		int		_contactCount;
	public:
		// Constructors and destructors
		Phonebook();
		~Phonebook();
		// Methods
		void	addContact();
		void	searchContact();
};

void	print_field(std::string field);
void	print_line(std::string index, std::string first_name, std::string last_name, std::string nickname);

#endif
