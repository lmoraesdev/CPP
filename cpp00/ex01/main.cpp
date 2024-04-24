#include "Phonebook.hpp"

int	main(void) {
	Phonebook	phonebook;
	std::string	input;

	std::cout << "Welcome to the Phonebook!" << std::endl << std::endl;
	while (1) {
		std::cout << "Valid commands: ADD, SEARCH, EXIT" << std::endl;
		std::cout << "\nPlease enter a command: ";
		std::getline(std::cin, input);
		if (input == "EXIT" || input == "exit") {
			std::cout << GREEN << "\nBye!" << RESET << std::endl;
			break ;
		}
		else if (input == "ADD" || input == "add") {
			phonebook.addContact();
		}
		else if (input == "SEARCH" || input == "search") {
			phonebook.searchContact();
		}
		else {
			std::cout << RED << "\nInvalid command. Please try again.\n" << RESET << std::endl;
		}
	}
	return (0);
}
