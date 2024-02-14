#include <iostream>
#include <cstring>

/* The line `using namespace std;` is a directive that allows us to use the names
of the standard library (std) without having to prefix them with `std::`. This
means that we can directly use names like `cout` and `endl` from the `std`
namespace without having to write `std::cout` and `std::endl`. */
using namespace std;

/**
 * This C++ program takes command line arguments and prints them in uppercase, or
 * if no arguments are provided, it prints a loud and unbearable feedback noise.
 *
 * @param argc The parameter `argc` is an integer that represents the number of
 * command-line arguments passed to the program. It includes the name of the
 * program itself as the first argument.
 * @param argv The `argv` parameter is an array of strings, where each string
 * represents a command-line argument passed to the program. The first element
 * `argv[0]` is the name of the program itself, and the subsequent elements
 * `argv[1]` to `argv[argc-1]`
 *
 * @return The main function is returning an integer value of 0.
 */
int main(int argc, char **argv)
{
	string buffer;

	if (argc < 2){
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
		return 0;
	}
	for (int x = 1; argv[x]; x++){
		for (int y = 0; argv[x][y]; y++){
			buffer += toupper(argv[x][y]);
		}
	}
	cout << buffer << endl;
    return 0;
}
