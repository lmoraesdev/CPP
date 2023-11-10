#include <iostream>
#include "Fixed.hpp"

/**
 * The main function creates three instances of the Fixed class, assigns the value
 * of one instance to another, and then prints the raw bits of each instance.
 *
 * @return The main function is returning 0.
 */
int main(void){
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return(0);
}
