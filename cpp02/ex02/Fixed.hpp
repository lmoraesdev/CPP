#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
private:
	int	fixed_number;
	static const int frac_bits_num = 8;
public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed(const int fixed);
	Fixed(const float fixed);
	~Fixed();
	Fixed	&operator = (const Fixed &fixed);
	int		getRawBits( void ) const;
	void	setRawBits( float const raw );
	float	toFloat()const;
	int		toInt()const;
	// comparison
	bool operator> (const Fixed &fixed)const;
	bool operator< (const Fixed &fixed)const;
	bool operator<= (const Fixed &fixed)const;
	bool operator>= (const Fixed &fixed)const;
	bool operator== (const Fixed &fixed)const;
	bool operator!= (const Fixed &fixed)const;

	// arithmetic
	Fixed &operator+ (const Fixed &fixed);
	Fixed &operator- (const Fixed &fixed);
	Fixed &operator* (const Fixed &fixed);
	Fixed &operator/ (const Fixed &fixed);

	// increment
	Fixed operator++ (int value);
	Fixed &operator++ (void);
	Fixed operator-- (int value);
	Fixed &operator-- (void);

	// Max and min
	static Fixed &min(Fixed &f1, Fixed &f2);
	static const Fixed &min(Fixed  const &f1, Fixed const &f2);
	static Fixed &max(Fixed &f1, Fixed &f2);
	static const Fixed &max(Fixed  const &f1, Fixed const &f2);
};

std::ostream &operator<<(std::ostream &out, const Fixed &num);

#endif
