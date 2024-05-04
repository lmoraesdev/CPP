#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) , _target("Undefined")
{
	std::cout << "Robotomy Request Form default constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "Robotomy Request Form target parameter constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & copy) : AForm("RobotomyRequestForm", 72, 45)
{
	*this = copy;
	std::cout << "Robotomy Request Form, copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Request Form, destructor called" << std::endl;
	return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=( RobotomyRequestForm const &copy )
{
	std::cout << "Robotomy Request Form, copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->_target = copy.getTarget();
	}
	return (*this);
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (!this->getSigned())
		throw AForm::FormNotSignException();
	else if (this->getGradeExecute() < executor.getGrade())
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << "* drilling noises can be heard *" << std::endl;
		if ((int)std::rand() % 2 != 0)
		{
			std::cout << this->_target << " has been robotomized." << std::endl;
		}
		else
		{
			std::cout << this->_target << " robotomization failed." << std::endl;
		}
	}
}

const char* RobotomyRequestForm::CreateFileException::what() const throw()
{
	return ("Something went wrong while doing the robotomization");
}
