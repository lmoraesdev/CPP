#include  <iostream>

/**
 * The function demonstrates the use of pointers and references in C++ to access
 * and manipulate a string variable.
 *
 * @return The program is returning 0.
 */
int main (void){
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << &brain << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << brain << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
	return (0);
}
