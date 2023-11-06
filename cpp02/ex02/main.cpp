#include "Fixed.hpp"

int main( void )
{
	{
		Fixed a(12.2f);
		Fixed b(13.2f);

		std::cout <<  "Comparação"<< std::endl;
		std::cout << "menor <" << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;

		if (a < b)
			std::cout << "a é menor\n";
		std::cout << "------------" << std::endl;

		std::cout << "maior >" << std::endl;
		a.setRawBits(15.6f);
		b.setRawBits(15.5f);
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;

		if (a > b)
			std::cout << "a é maior\n";
		std::cout << "------------" << std::endl;

		std::cout << "igual ==" << std::endl;
		a.setRawBits(15.5f);
		b.setRawBits(15.5f);
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;

		if (a == b)
			std::cout << "iguais\n";

		std::cout << "------------" << std::endl;

		std::cout << "deferente !=" << std::endl;
		a.setRawBits(15.5f);
		b.setRawBits(15.4f);
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;

		if (a != b)
			std::cout << "diferentes\n";

		std::cout << "---------------------" << std::endl;
		std::cout << "Aritmeticos" << std::endl;

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << "soma a + b: a = " ;
		a + b;
		std::cout << a << std::endl;

		std::cout << "sub a - b: a = ";
		a - b;
		std::cout << a << std::endl;

		std::cout << "mult a * b: a = ";
		a * b;
		std::cout << a << std::endl;

		std::cout << "div a / b: a = " ;
		a / b;
		std::cout << a << std::endl;
		std::cout << "---------------------" << std::endl;

		std::cout << "Incremento" << std::endl;
		std::cout << "++a\n a antes: "<< a << std::endl;
		std::cout << "a depois: "<< ++a << std::endl;

		std::cout << "a++\n a antes: "<< a << std::endl;
		std::cout << "a depois: "<< a++ << std::endl;

		std::cout << "--a\n a antes: "<< a << std::endl;
		std::cout << "a depois: "<< --a << std::endl;

		std::cout << "a--\n a antes: "<< a << std::endl;
		std::cout << "a depois: "<< a-- << std::endl;
		std::cout << "a depois: "<< a << std::endl;

		std::cout << "---------------------" << std::endl;

		std::cout << "Max / min" << std::endl;
		std::cout << "Max " << std::endl;
		a.setRawBits(5.7f);
		b.setRawBits(5.0f);
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << Fixed::max(a, b) << std::endl;

		std::cout << "Min" << std::endl;
		a.setRawBits(18.9f);
		b.setRawBits(4.6f);
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << Fixed::min(a, b) << std::endl;}
	{
		std::cout << "Max const" << std::endl;
		Fixed const c(15.6f);
		Fixed const d(8.6f);
		std::cout << "c = " << c << std::endl;
		std::cout << "d = " << d << std::endl;
		std::cout << Fixed::max(c, d) << std::endl;
	}
	{
		std::cout << "Min const" << std::endl;
		Fixed const c(15.6f);
		Fixed const d(8.6f);
		std::cout << "c = " << c << std::endl;
		std::cout << "d = " << d << std::endl;
		std::cout << Fixed::min(c, d) << std::endl;
	}
}
