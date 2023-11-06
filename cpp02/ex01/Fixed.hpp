#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
private:
	int	fixed_number;
	static const int frac_bits_num = 8;
public:
	Fixed(/* args */);
	Fixed(const Fixed &fixed);
	Fixed(const int fixed);
	Fixed(const float fixed);
	~Fixed();
	Fixed	&operator = (const Fixed &fixed);
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat()const;
	int		toInt()const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &num);

#endif
