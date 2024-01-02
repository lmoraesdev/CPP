#if !defined(CONV_HPP)
# define CONV_HPP

#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cctype>


class Conv
{
protected:
	std::string input;
	int	_int;
	float _float;
	double _double;
	char _char;
public:
	Conv(std::string input);
	Conv(const Conv &ref);
	Conv	&operator=(Conv const &ref);
	~Conv();
	// Functions
	void parse();
	void special();
	void printInf();
	void printNan();
	void validate();
	void toFloat();
	void toInt();
	void toChar();
	void toDouble();
	void print();

};

#endif
