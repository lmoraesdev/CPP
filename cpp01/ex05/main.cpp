#include "Harl.hpp"


/**
 * The main function creates an instance of the Harl class and calls the complain
 * method with different log levels.
 *
 * @return The main function is returning 0.
 */
int main (){
	Harl harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");

	return (0);
}
