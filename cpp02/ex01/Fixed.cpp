#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/**
 * The above function is the default constructor for the Fixed class in C++, which
 * initializes the fixed_number variable to 0 and prints a message to the console.
 */
Fixed::Fixed(/* args */)
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
 * The function is a constructor for the Fixed class that takes an integer argument
 * and initializes the fixed_number member variable.
 *
 * @param fixed The parameter "fixed" is an integer value that represents the
 * fixed-point number.
 */
Fixed::Fixed(const int fixed)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_number = (int)fixed << this->frac_bits_num;
}

/**
 * The function is a constructor for the Fixed class that takes a float as input
 * and converts it to a fixed-point representation.
 *
 * @param fixed The "fixed" parameter is a floating-point number that represents
 * the value to be stored in the fixed-point number.
 */
Fixed::Fixed(const float fixed)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_number = (int)roundf(fixed * (1 << this->frac_bits_num));
}

/**
 * The function returns the value of the fixed_number variable.
 *
 * @return the value of the member variable "fixed_number".
 */
int Fixed::getRawBits(void)const{
	return (this->fixed_number);
}

/**
 * The function sets the value of the fixed_number variable to the given raw value.
 *
 * @param raw The parameter "raw" is an integer value that represents the raw bits
 * of a fixed-point number.
 */
void Fixed::setRawBits(int const raw){
	this->fixed_number = raw;
}

/**
 * The function is a copy assignment operator that assigns the value of a Fixed
 * object to another Fixed object.
 *
 * @return The reference to the current object is being returned.
 */
Fixed	&Fixed::operator= (const Fixed &fixed)
{
	std::cout <<"Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->fixed_number = fixed.getRawBits();
	return (*this);
}

/**
 * The function converts a fixed-point number to an integer by shifting the bits
 * and extracting the integer part.
 *
 * @return the integer value of the fixed number.
 */
int	Fixed::toInt()const{
	// desloca os bits ate o ponto e pega a parte inteira
	return((int)this->fixed_number >> Fixed::frac_bits_num);
}

/**
 * The function converts a fixed-point number to a floating-point number.
 *
 * @return a float value.
 */
float	Fixed::toFloat()const{

	return((float)(this->fixed_number) / (1 << this->frac_bits_num));
}

/**
 * The above function overloads the << operator to allow for the output of a Fixed
 * object to an ostream.
 *
 * @return The output stream object "out" is being returned.
 */
std::ostream	&operator<<(std::ostream &out, const Fixed &num){
	out << num.toFloat();
	return (out);
}
