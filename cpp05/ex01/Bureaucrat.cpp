#include "Bureaucrat.hpp"
#include "Form.hpp"

// Constructors and destructor
Bureaucrat::Bureaucrat(void) {
	return ;
}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < _max_grade)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > _min_grade)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
	return ;
}
Bureaucrat::Bureaucrat(const Bureaucrat &source) : _name(source._name) {
	*this = source;
	return ;
}
Bureaucrat::~Bureaucrat(void) {
	return ;
}

// Operator overloads
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &source) {
	if (this == &source)
		return (*this);
	_grade = source._grade;
	return (*this);
}

// Getters
std::string	Bureaucrat::getName(void) const {
	return (_name);
}
int			Bureaucrat::getGrade(void) const {
	return (_grade);
}

// Member functions
void		Bureaucrat::incrementGrade(void) {
	if (_grade - 1 < _max_grade)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}
void		Bureaucrat::decrementGrade(void) {
	if (_grade + 1 > _min_grade)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

// Sign form
void		Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << GREEN << _name << RESET << " signed " << GREEN << form.getName() << RESET << "." << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << _name << RESET << " couldn't sign " << RED << form.getName() << RESET << " because " << RED << e.what() << RESET << std::endl;
	}
}

// Exception classes
const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return (RED "Grade too high!" RESET);
}
const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return (RED "Grade too low!" RESET);
}

// Stream operator overload
std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << YELLOW << bureaucrat.getName() << RESET << ", bureaucrat grade " << GREEN << bureaucrat.getGrade() << RESET << ".";
	return (os);
}
