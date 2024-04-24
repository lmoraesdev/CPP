#include "Fixed.hpp"

int main(void) {
	// declare a variable of type Fixed
	Fixed a;
	// declare a copy of Fixed a
	Fixed b(a);
	// declare another variable of type Fixed
	Fixed c;
	// assign b to c
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return (0);
}
