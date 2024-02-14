#include  <iostream>
#include  "Span.hpp"

int main (void){

	Span	array(5);

	array.addNumber(8);
	array.addNumber(1);
	array.addNumber(3);
	array.addNumber(10);
	array.addNumber(5);

	std::cout << array.longestSpan() << "\n";
	std::cout << array.shortestSpan() << "\n";

	return (0);
}
