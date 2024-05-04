#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"


int	main(void)
{
	std::cout << "\n------- Presidential Pardon Form -------" << std::endl;
	Bureaucrat zorgon2("Prostetnic Vogon Kwaltz", 26);
	PresidentialPardonForm formulary("Phineas");
	try {
		formulary.beSigned(zorgon2);
	}
	catch (const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	try {
		zorgon2.executeForm(formulary);
	}
	catch (const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	zorgon2.setGrade(4);
	formulary.beSigned(zorgon2);
	try {
		formulary.beSigned(zorgon2);
	}
	catch (const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	try {
		zorgon2.executeForm(formulary);
	}
	catch (const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n\n-------- Shrubbery Request Form --------" << std::endl;
	Bureaucrat zorgon3("Prostetnic Vogon Jeltz", 150);

	ShrubberyCreationForm formulary1("Knights who say NI");
	try {
		formulary1.beSigned(zorgon3);
	}
	catch (const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	try {
		zorgon3.executeForm(formulary1);
	}
	catch (const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	zorgon3.setGrade(5);
	try {
		formulary1.beSigned(zorgon3);
	}
	catch (const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	try {
		zorgon3.executeForm(formulary1);
	}
	catch (const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n\n--------- Robotomy Request Form --------" << std::endl;
	Bureaucrat zorgon4("Zarniwoop", 46);

	RobotomyRequestForm formulary2("Roboto");
	try {
		formulary2.execute(zorgon4);
	}
	catch (const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	formulary2.beSigned(zorgon4);
	zorgon4.incrementGrade();
	zorgon4.executeForm(formulary2);
	zorgon4.executeForm(formulary2);
	std::cout << "\n\n---------- Default Destructors ---------" << std::endl;
	return (0);
}
