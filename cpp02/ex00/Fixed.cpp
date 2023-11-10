#include "Fixed.hpp"
#include <iostream>

/**
 * The above function is the default constructor for the Fixed class in C++, which
 * initializes the fixed_number variable to 0 and prints a message.
 */
Fixed::Fixed()
{
	this->fixed_number = 0;
	std::cout << "Default constructor called" << std::endl;
}

/**
 * The above code snippet is a destructor for a C++ class called Fixed, which
 * outputs "Destructor called" when the destructor is called.
 */
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/**
 * The above function is a copy constructor for the Fixed class in C++.
 *
 * @param fixed The parameter "fixed" is a reference to an object of the class
 * "Fixed".
 */
Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

/**
 * The function is the copy assignment operator for the Fixed class in C++, which
 * assigns the value of one Fixed object to another.
 *
 * @param fixed The parameter "fixed" is a reference to an object of type "Fixed".
 */
void	Fixed::operator= (const Fixed &fixed)
{
	std::cout <<"Copy assignment operator called" << std::endl;
	this->fixed_number = fixed.getRawBits();
}

/**
 * The function returns the value of the fixed_number variable.
 *
 * @return the value of the member variable "fixed_number".
 */
int Fixed::getRawBits(void)const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_number);
}

/**
 * The function sets the value of the fixed_number variable to the given raw value.
 *
 * @param raw The parameter "raw" is an integer value that represents the raw bits
 * of a fixed-point number.
 */
void Fixed::setRawBits( int const raw ){
	this->fixed_number = raw;
}
