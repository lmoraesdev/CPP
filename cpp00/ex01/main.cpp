#include "PhoneBook.hpp"

/**
 * The function "check_input" takes a string input and a pointer to a PhoneBook
 * object, and based on the input, either adds a contact, shows the contacts, or
 * exits the program.
 *
 * @param input A string representing the user's input command.
 * @param lista The parameter "lista" is a pointer to an object of type
 * "PhoneBook".
 */
void check_input(std::string input, PhoneBook *lista){
	if (input == "add" || input == "ADD")
		lista->addContact();
	else if (input == "search" || input == "SEARCH")
		lista->showContacts();
	else if (input == "exit" || input == "EXIT")
		lista->is_open = 0;
}

/**
 * The main function creates a PhoneBook object and allows the user to add new
 * contacts, search for contacts, or exit the program.
 */
int main(void)
{
	PhoneBook lista;
	std :: string input;

	while (lista.is_open){
		std::cout << "-----------------------------------------------------" << std::endl;
		std::cout << "| Use ADD to create a new contact                   |"<< std ::endl;
		std::cout << "| SEARCH to see contacts                            |" << std::endl;
		std::cout << "| EXIT to close PhoneBook (you will lose all datas) |" << std::endl;
		std::cout << "-----------------------------------------------------" << std::endl;
		std::getline(std::cin, input);
		check_input(input, &lista);
		input.erase(0, -1);
	}
}
