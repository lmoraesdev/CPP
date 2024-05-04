#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define FORMS 3

class	Intern
{
	private:
		AForm	*_makeShrubberyCreationForm( std::string target );
		AForm	*_makeRobotomyRequestForm( std::string target );
		AForm	*_makePresidentialPardonForm( std::string target );
	public:
		Intern();
		Intern( Intern const& copy );
		~Intern();
		Intern &	operator=( Intern const &rhs );

		AForm		*makeForm( std::string name, std::string target );
};

#endif
