#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	int	fixed_number;
	static const int frac_bits_num = 8;
public:
	Fixed();
	Fixed(const Fixed &fixed);
	void	operator= (const Fixed &fixed);
	~Fixed();
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif
