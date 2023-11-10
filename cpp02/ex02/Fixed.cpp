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
 * The function sets the value of the fixed_number variable by converting the raw
 * float value to an integer using rounding and multiplying it by a constant.
 *
 * @param raw The raw value that needs to be converted and stored in the
 * fixed_number variable.
 */
void Fixed::setRawBits( float const raw ){
	this->fixed_number = (int)roundf(raw * (1 << this->frac_bits_num));
}

/**
 * The above function is the copy assignment operator for the Fixed class in C++,
 * which assigns the value of one Fixed object to another.
 *
 * @return The reference to the current object is being returned.
 */
Fixed	&Fixed::operator = (const Fixed &fixed)
{
	std::cout <<"Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->fixed_number = fixed.getRawBits();
	return (*this);
}

/**
 * The function converts the fixed-point number to an integer by shifting the bits
 * to the right.
 *
 * @return the fixed number converted to an integer.
 */
int	Fixed::toInt()const{
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

/**
 * The above function compares two Fixed objects and returns true if the calling
 * object is greater than the passed object, otherwise it returns false.
 *
 * @param fixed The "fixed" parameter is a reference to another object of the same
 * class "Fixed".
 *
 * @return a boolean value, either true or false.
 */
bool Fixed::operator> (const Fixed &fixed)const{
	float f1 = this->toFloat();
	float f2 = fixed.toFloat();
	return (f1 > f2 ? true : false);
}
/**
 * The function compares two Fixed objects and returns true if the first object is
 * less than the second object, otherwise it returns false.
 *
 * @param fixed The "fixed" parameter is a reference to another object of the Fixed
 * class.
 *
 * @return a boolean value, either true or false.
 */
bool Fixed::operator< (const Fixed &fixed)const{
	float f1 = this->toFloat();
	float f2 = fixed.toFloat();
	return (f1 < f2 ? true : false);
}

/**
 * The function checks if the value of the current Fixed object is less than or
 * equal to the value of the passed Fixed object.
 *
 * @param fixed The "fixed" parameter is a reference to another object of the same
 * class "Fixed".
 *
 * @return a boolean value. It returns true if the value of the current Fixed
 * object is less than or equal to the value of the passed Fixed object, and false
 * otherwise.
 */
bool Fixed::operator<= (const Fixed &fixed)const{
	float f1 = this->toFloat();
	float f2 = fixed.toFloat();
	return (f1 <= f2 ? true : false);
}

/**
 * The function checks if the value of the current Fixed object is greater than or
 * equal to the value of the passed Fixed object.
 *
 * @param fixed The "fixed" parameter is a reference to another object of the same
 * class "Fixed".
 *
 * @return a boolean value, either true or false.
 */
bool Fixed::operator>= (const Fixed &fixed)const{
	float f1 = this->toFloat();
	float f2 = fixed.toFloat();
	return (f1 >= f2 ? true : false);
}

/**
 * The function checks if two Fixed objects are equal by converting them to floats
 * and comparing their values.
 *
 * @param fixed The "fixed" parameter is a reference to another object of the Fixed
 * class.
 *
 * @return a boolean value, either true or false.
 */
bool Fixed::operator== (const Fixed &fixed)const{
	float f1 = this->toFloat();
	float f2 = fixed.toFloat();
	return (f1 == f2 ? true : false);
}

/**
 * The function checks if two Fixed objects are not equal by converting them to
 * floats and comparing them.
 *
 * @param fixed The "fixed" parameter is a reference to another object of the Fixed
 * class.
 *
 * @return a boolean value.
 */
bool Fixed::operator!= (const Fixed &fixed)const{
	float f1 = this->toFloat();
	float f2 = fixed.toFloat();
	return (f1 != f2 ? true : false);
}

/**
 * The above function overloads the "+" operator to add two Fixed objects together
 * and return the result.
 *
 * @return a reference to the current object, which is represented by `*this`.
 */
Fixed &Fixed::operator+ (const Fixed &fixed){
	this->fixed_number += fixed.fixed_number;
	return *this;
}

/**
 * The above function overloads the subtraction operator for the Fixed class in
 * C++.
 *
 * @return a reference to the current object, which is represented by `*this`.
 */
Fixed &Fixed::operator- (const Fixed &fixed){
	this->fixed_number -= fixed.fixed_number;
	return *this;
}

/**
 * The above function overloads the * operator to multiply two Fixed objects and
 * update the value of the calling object.
 *
 * @return The object that the operator* function is being called on is being
 * returned.
 */
Fixed &Fixed::operator* (const Fixed &fixed){
	this->fixed_number *= fixed.fixed_number;
	return *this;
}

/**
 * The above function overloads the division operator for the Fixed class.
 *
 * @return The reference to the current object is being returned.
 */
Fixed &Fixed::operator/ (const Fixed &fixed){
	this->fixed_number /= fixed.fixed_number;
	return *this;
}

/**
 * The above function overloads the pre-increment operator for the Fixed class in
 * C++, incrementing the fixed_number member variable and returning a reference to
 * the updated object.
 *
 * @return The object itself is being returned.
 */
Fixed &Fixed::operator++ (void){
	this->fixed_number++;
	return (*this);
}

/**
 * The above function overloads the post-increment operator for the Fixed class in
 * C++.
 *
 * @param value The parameter "value" in the above code is not used and is
 * therefore unnecessary. It can be removed from the function signature.
 *
 * @return The value of the Fixed object before it was incremented.
 */
Fixed Fixed::operator++ (int value){
	Fixed holder = *this;
	this->fixed_number++;
	return (holder);
}

/**
 * The above function is an overloaded decrement operator for the Fixed class in
 * C++, which decrements the fixed_number member variable and returns a reference
 * to the updated object.
 *
 * @return The `Fixed` object that has been decremented by 1.
 */
Fixed &Fixed::operator-- (void){
	this->fixed_number--;
	return (*this);
}

/**
 * The above function overloads the post-decrement operator for the Fixed class in
 * C++.
 *
 * @param value The parameter "value" in the above code is not used in the
 * implementation of the operator-- function. It is declared but not used anywhere
 * in the function body.
 *
 * @return The value of the Fixed object before the decrement operation is
 * performed.
 */
Fixed Fixed::operator-- (int value){
	Fixed holder = *this;
	this->fixed_number--;
	return (holder);
}

/**
 * The function returns the minimum value between two Fixed objects.
 *
 * @return A reference to a constant Fixed object is being returned.
 */
Fixed &Fixed::min(Fixed &f1, Fixed &f2){
	if (f1 < f2)
		return f1;
	return f2;
}

/**
 * The function returns the minimum value between two Fixed objects.
 *
 * @return a reference to a constant Fixed object.
 */
const Fixed &Fixed::min(Fixed const &f1, Fixed const &f2){
	if (f1 < f2)
		return f1;
	return f2;

}

/**
 * The function returns the maximum value between two Fixed objects.
 *
 * @return the larger of the two Fixed objects, f1 or f2.
 */
Fixed &Fixed::max(Fixed &f1, Fixed &f2){
	if (f1 > f2)
		return f1;
	return f2;
}

/**
 * The function returns the maximum value between two Fixed objects.
 *
 * @return a reference to a constant Fixed object.
 */
const Fixed &Fixed::max(Fixed  const &f1, Fixed const &f2){
	if (f1 > f2)
		return f1;
	return f2;
}
