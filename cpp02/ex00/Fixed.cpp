#include "Fixed.hpp"

// Constructor
Fixed::Fixed(void) : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

// Copy constructor
Fixed::Fixed(const Fixed &other) : _rawBits(other._rawBits) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
	return ;
}

// Destructor
Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

// Operator overload
Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	_rawBits = other.getRawBits();
	return (*this);
}

// Setters and getters
int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_rawBits = raw;
	return ;
}
