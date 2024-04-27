#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	std::cout << std::endl << YELLOW << "------ Creating a Bureaucrat with grade 1 ------" << RESET << std::endl;
	Bureaucrat b1("Bureaucrat 1", 1);
	std::cout << b1 << std::endl;
	std::cout << std::endl << YELLOW << "------ Creating a Bureaucrat with grade 150 ------" << RESET << std::endl;
	Bureaucrat b2("Bureaucrat 2", 150);
	std::cout << b2 << std::endl;
	std::cout << std::endl << YELLOW << "------ Creating a Form with grade to sign 1 and grade to execute 1 ------" << RESET << std::endl;
	Form f1("Form 1", 1, 1);
	std::cout << f1 << std::endl;
	std::cout << std::endl << YELLOW << "------ Creating a Form with grade to sign 150 and grade to execute 150 ------" << RESET << std::endl;
	Form f2("Form 2", 150, 150);
	std::cout << f2 << std::endl;
	std::cout << std::endl << YELLOW << "------ Creating a Form with grade to sign 1 and grade to execute 150 ------" << RESET << std::endl;
	Form f3("Form 3", 1, 150);
	std::cout << f3 << std::endl;
	std::cout << std::endl << YELLOW << "------ Creating a Form with grade to sign 150 and grade to execute 1 ------" << RESET << std::endl;
	Form f4("Form 4", 150, 1);
	std::cout << f4 << std::endl;
	std::cout << std::endl << YELLOW << "------ Creating a Form with grade to sign 0 and grade to execute 1 ------" << RESET << std::endl;
	try {
		Form f5("Form 5", 0, 1);
		std::cout << f5 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl << YELLOW << "------ Creating a Form with grade to sign 1 and grade to execute 0 ------" << RESET << std::endl;
	try {
		Form f6("Form 6", 1, 0);
		std::cout << f6 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl << YELLOW << "------ Creating a Form with grade to sign 151 and grade to execute 1 ------" << RESET << std::endl;
	try {
		Form f7("Form 7", 151, 1);
		std::cout << f7 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl << YELLOW << "------ Creating a Form with grade to sign 1 and grade to execute 151 ------" << RESET << std::endl;
	try {
		Form f8("Form 8", 1, 151);
		std::cout << f8 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	// Sign a form
	std::cout << std::endl << YELLOW << "------ Signing a form with a bureaucrat with grade 1 ------" << RESET << std::endl;
	b1.signForm(f1);
	std::cout << f1 << std::endl;
	std::cout << std::endl << YELLOW << "------ Signing a form with a bureaucrat with grade 150 ------" << RESET << std::endl;
	b2.signForm(f2);
	std::cout << f2 << std::endl;
	std::cout << std::endl << YELLOW << "------ Signing a form with a bureaucrat with grade 1 ------" << RESET << std::endl;
	b1.signForm(f3);
	std::cout << f3 << std::endl;
	std::cout << std::endl << YELLOW << "------ Signing a form with a bureaucrat with grade 150 ------" << RESET << std::endl;
	b2.signForm(f4);
	std::cout << f4 << std::endl;
	// Try to sign a form
	std::cout << std::endl << YELLOW << "------ Trying to sign a form with a bureaucrat with grade 150 ------" << RESET << std::endl;
	b2.signForm(f1);
	std::cout << f1 << std::endl;
	std::cout << std::endl << YELLOW << "------ Trying to sign a form with a bureaucrat with grade 1 ------" << RESET << std::endl;
	b1.signForm(f2);
	std::cout << f2 << std::endl;
	return (0);
}
