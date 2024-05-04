#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) , _target("Undefined")
{
	std::cout << "Presidential Pardon Form default constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "Presidential Pardon Form target parameter constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & copy) : AForm("PresidentialPardonForm", 25, 5)
{
	*this = copy;
	std::cout << "Presidential Pardon Form, copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Pardon Form, destructor called" << std::endl;
	return ;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=( PresidentialPardonForm const &copy )
{
	std::cout << "Presidential Pardon Form, copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->_target = copy.getTarget();
	}
	return (*this);
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (!this->getSigned())
		throw AForm::FormNotSignException();
	else if (this->getGradeExecute() < executor.getGrade())
		throw AForm::GradeTooLowException();
	else
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

const char* PresidentialPardonForm::CreateFileException::what() const throw()
{
	return ("Something went wrong with the pardon");
}
