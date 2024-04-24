#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	static const int	fractionalBits = 8;
	int					_rawBits;

public:
	// Constructors
	Fixed(void);
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &other);
	// Destructor
	~Fixed(void);
	// Assignment Operator overload
	Fixed	&operator=(const Fixed &other);
	// Member functions
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

// Non-member function
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
