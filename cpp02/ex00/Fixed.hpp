#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	static const int	fractionalBits = 8;
	int					_rawBits;

public:
	// Default Constructor
	Fixed(void);
	// Copy constructor
	Fixed(const Fixed &other);
	// Destructor
	~Fixed(void);
	// Operator overload
	Fixed	&operator=(const Fixed &other);
	// Setters and getters
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif
