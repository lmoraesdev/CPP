#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(/* args */)
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
/*
	1
	00000001

	1 << 8

	10000000
	1
	no sistema de ponto fixo, a representação do inteiro começa na 8 casa dos binarios
*/
Fixed::Fixed(const int fixed)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_number = (int)fixed << this->frac_bits_num;
}

Fixed::Fixed(const float fixed)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_number = (int)roundf(fixed * (1 << this->frac_bits_num));
}

int Fixed::getRawBits(void)const{
	return (this->fixed_number);
}

void Fixed::setRawBits(int const raw){
	this->fixed_number = raw;
}

Fixed	&Fixed::operator= (const Fixed &fixed)
{
	std::cout <<"Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->fixed_number = fixed.getRawBits();
	return (*this);
}

int	Fixed::toInt()const{
	// desloca os bits ate o ponto e pega a parte inteira
	return((int)this->fixed_number >> Fixed::frac_bits_num);
}

float	Fixed::toFloat()const{

	return((float)(this->fixed_number) / (1 << this->frac_bits_num));
}

std::ostream	&operator<<(std::ostream &out, const Fixed &num){
	out << num.toFloat();
	return (out);
}
