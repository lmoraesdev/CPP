#include  <iostream>
#include  "Bureaucrat.hpp"

int main (void){

// certo
	try
	{
		Form form("form1", 10, 20);
		Bureaucrat bure("bure1", 20);
		bure.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form form("form2", 10, 15);
		Bureaucrat bure("bure2", 20);
		bure.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	return (0);
}
