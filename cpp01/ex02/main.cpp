#include <iostream>
#include <string>

int	main(void) {
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

	// Title
	std::cout << std::endl;
	std::cout << "POINTER VS REFERENCE" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;

	// Variables
	std::cout << "str = \"" << str << "\"" << std::endl;
	std::cout << "std::string* stringPTR = &str" << std::endl;
	std::cout << "std::string& stringREF = str" << std::endl;
	std::cout << std::endl;

    // Print the memory addresses
    std::cout << "Memory address of the string variable: " << &str << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;
	std::cout << std::endl;

    // Print the values
    std::cout << "Value of the string variable: " << str << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
	std::cout << std::endl;

    return 0;
}
