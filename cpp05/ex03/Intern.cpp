#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
	return ;
}

Intern::Intern( const Intern& copy )
{
	std::cout << "Intern, copy constructor called" << std::endl;
	*this = copy;
	return ;
}

Intern::~Intern(void)
{
	std::cout << "Intern, destructor called" << std::endl;
	return ;
}

Intern &Intern::operator=(Intern const &copy)
{
	std::cout << "Intern, copy assignment operator called" << std::endl;
	if (this != &copy)
	{ }
	return (*this);
}

AForm*	Intern::makeForm( std::string name, std::string target )
{
	AForm *(Intern::*formFunction[FORMS])(std::string target) =
	{
		&Intern::_makeShrubberyCreationForm,
		&Intern::_makeRobotomyRequestForm,
		&Intern::_makePresidentialPardonForm,
	};

	std::string	formTypes[FORMS] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon",
	};

	std::string	formNames[FORMS] = {
		"Shrubbery Creation Form",
		"Robotomy Request Form",
		"Presidential Pardon Form",
	};

	for (int i = 0; i < FORMS; i++)
	{
		if (name == formTypes[i])
		{
			std::cout << "Intern creates " << formNames[i] << std::endl;
			return (this->*formFunction[i])(target);
	}
	}
	std::cout << name << " is not a valid form." << std::endl;
	return (NULL);
}

AForm* Intern::_makeShrubberyCreationForm( std::string target )
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::_makeRobotomyRequestForm( std::string target )
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::_makePresidentialPardonForm( std::string target )
{
	return new PresidentialPardonForm(target);
}
