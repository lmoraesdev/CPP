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

void Fixed::setRawBits( float const raw ){
	this->fixed_number = (int)roundf(raw * (1 << this->frac_bits_num));
}

Fixed	&Fixed::operator = (const Fixed &fixed)
{
	std::cout <<"Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->fixed_number = fixed.getRawBits();
	return (*this);
}

// desloca os bits ate o ponto e pega a parte inteira
int	Fixed::toInt()const{
	return((int)this->fixed_number >> Fixed::frac_bits_num);
}

float	Fixed::toFloat()const{

	return((float)(this->fixed_number) / (1 << this->frac_bits_num));
}

std::ostream	&operator<<(std::ostream &out, const Fixed &num){
	out << num.toFloat();
	return (out);
}

bool Fixed::operator> (const Fixed &fixed)const{
	float f1 = this->toFloat();
	float f2 = fixed.toFloat();
	return (f1 > f2 ? true : false);
}
bool Fixed::operator< (const Fixed &fixed)const{
	float f1 = this->toFloat();
	float f2 = fixed.toFloat();
	return (f1 < f2 ? true : false);
}

bool Fixed::operator<= (const Fixed &fixed)const{
	float f1 = this->toFloat();
	float f2 = fixed.toFloat();
	return (f1 <= f2 ? true : false);
}

bool Fixed::operator>= (const Fixed &fixed)const{
	float f1 = this->toFloat();
	float f2 = fixed.toFloat();
	return (f1 >= f2 ? true : false);
}

bool Fixed::operator== (const Fixed &fixed)const{
	float f1 = this->toFloat();
	float f2 = fixed.toFloat();
	return (f1 == f2 ? true : false);
}

bool Fixed::operator!= (const Fixed &fixed)const{
	float f1 = this->toFloat();
	float f2 = fixed.toFloat();
	return (f1 != f2 ? true : false);
}

Fixed &Fixed::operator+ (const Fixed &fixed){
	this->fixed_number += fixed.fixed_number;
	return *this;
}

Fixed &Fixed::operator- (const Fixed &fixed){
	this->fixed_number -= fixed.fixed_number;
	return *this;
}

Fixed &Fixed::operator* (const Fixed &fixed){
	this->fixed_number *= fixed.fixed_number;
	return *this;
}

Fixed &Fixed::operator/ (const Fixed &fixed){
	this->fixed_number /= fixed.fixed_number;
	return *this;
}

Fixed &Fixed::operator++ (void){
	this->fixed_number++;
	return (*this);
}

Fixed Fixed::operator++ (int value){
	Fixed holder = *this;
	this->fixed_number++;
	return (holder);
}

Fixed &Fixed::operator-- (void){
	this->fixed_number--;
	return (*this);
}

Fixed Fixed::operator-- (int value){
	Fixed holder = *this;
	this->fixed_number--;
	return (holder);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2){
	if (f1 < f2)
		return f1;
	return f2;
}

const Fixed &Fixed::min(Fixed const &f1, Fixed const &f2){
	if (f1 < f2)
		return f1;
	return f2;

}

Fixed &Fixed::max(Fixed &f1, Fixed &f2){
	if (f1 > f2)
		return f1;
	return f2;
}

const Fixed &Fixed::max(Fixed  const &f1, Fixed const &f2){
	if (f1 > f2)
		return f1;
	return f2;
}
