#if !defined(SPAN_HPP)
# define SPAN_HPP

#include <iostream>
#include <exception>

class Span
{
private:
	int *array;
	unsigned int size;
	unsigned int	index;

protected:

public:
	Span(unsigned int size);
	Span(const Span &ref);
	Span	&operator=(Span const &ref);
	~Span();
	struct IsFull : public std::exception
	{
		const char *what() const throw(){
			return ("Array is full");
		}
	};

	void addNumber(int num);
	int getLow();
	int getSecondLow();
	int getHigh();
	int shortestSpan();
	int longestSpan();
};

#endif
