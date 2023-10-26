#include "PhoneBook.hpp"

void check_input(std::string input, PhoneBook *lista){
	if (input == "add" || input == "ADD")
		lista->addContact();
	else if (input == "search" || input == "SEARCH")
		lista->showContacts();
	else if (input == "exit" || input == "EXIT")
		lista->is_open = 0;
}

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
