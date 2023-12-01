#include  <iostream>
#include  "Bureaucrat.hpp"

int main (void){

	try
	{
		Bureaucrat teste("Claudio", 1);
		teste++;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat teste("Joao", 150);
		teste--;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat teste("Maria", 10);
		std::cout << teste;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
