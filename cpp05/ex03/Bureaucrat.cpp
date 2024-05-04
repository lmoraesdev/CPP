#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Vogon"), _grade(75)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string const name, int const grade) : _name(name)
{
	std::cout << "Bureaucrat " << name << ", parameter constructor called" << std::endl;
	setGrade(grade);
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
	std::cout << "Bureaucrat " << copy.getName() << ", copy constructor called" << std::endl;
	*this = copy;
	return ;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << _name << ", destructor called" << std::endl;
	return ;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &copy)
{
	std::cout << "Bureaucrat " << copy.getName() << ", copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		const_cast<std::string&>(this->_name) = copy.getName();
		this->_grade = copy.getGrade();
	}
	return (*this);
}

void	Bureaucrat::setGrade(int const grade)
{
	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

int	Bureaucrat::getGrade(void) const
{
	return(_grade);
}

std::string Bureaucrat::getName(void) const
{
	return (_name);
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade == MAX_GRADE) { throw GradeTooHighException (); }
	this->_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade == MIN_GRADE) { throw GradeTooLowException (); }
	this->_grade++;
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << getName() << " couldn't sign " << form.getName()
				<< " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << this->_name << " couldn't execute " << form.getName() << " "
				<< e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade Too High Exception");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade Too Low Exception");
}

std::ostream &operator<<(std::ostream &outputFile, Bureaucrat const &bureaucrat)
{
	outputFile	<< bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return (outputFile);
}
