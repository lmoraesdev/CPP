#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
	this->fixed_number = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

void	Fixed::operator= (const Fixed &fixed)
{
	std::cout <<"Copy assignment operator called" << std::endl;
	this->fixed_number = fixed.getRawBits();
}

int Fixed::getRawBits(void)const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_number);
}

void Fixed::setRawBits( int const raw ){
	this->fixed_number = raw;
}
