#include "Harl.hpp"

/**
 * The main function takes a command line argument, converts it to uppercase, and
 * passes it to the complain function of the Harl object.
 *
 * @param argc The parameter `argc` stands for "argument count" and it represents
 * the number of command-line arguments passed to the program. It includes the name
 * of the program itself as the first argument.
 * @param argv The `argv` parameter is an array of strings that represents the
 * command-line arguments passed to the program. In this case, `argv` is of type
 * `char**`, which means it is an array of pointers to characters.
 *
 * @return The main function is returning 0.
 */
int main (int argc, char **argv){

	Harl harl;
	if(argc != 2)
		return 0;
	std::string buffer;
	for (int y = 0; argv[1][y]; y++){
		buffer += toupper(argv[1][y]);
	}
	harl.complain(buffer);
	return (0);
}
