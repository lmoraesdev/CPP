#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade) : name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref) : name(ref.getName()) , grade(ref.getGrade())
{
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat contructor by copy" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor of Bureaucrat " << " called" <<std::endl;
}

Bureaucrat		&Bureaucrat::operator=(Bureaucrat const &ref)
{
	std::cout << "Assignation with operator= called" <<std::endl;
	if (this != &ref)
	{
		this->grade = ref.getGrade();
	}
	return *this;
}


std::string Bureaucrat::getName()const{
	return (this->name);
}

int Bureaucrat::getGrade()const{
	return (this->grade);
}

Bureaucrat Bureaucrat::operator++ (int value){
	Bureaucrat holder = *this;
	this->grade--;
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	return (holder);
}//posincremento

Bureaucrat Bureaucrat::operator-- (int value){
	Bureaucrat holder = *this;
	this->grade++;
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return (holder);
}//posincremento

Bureaucrat &Bureaucrat::operator++ (){
	this->grade--;
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	return (*this);
}

Bureaucrat &Bureaucrat::operator-- (){
	this->grade++;
	if (this->grade > 150)
		throw Bureaucrat::GradeTooHighException();
	return (*this);
}

void	Bureaucrat::signForm(Form &form){
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() <<" signed "<< form.getName() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << this->getName() <<" couldn’t sign "<< form.getName() << " because " << e.what() << std::endl;
	}

}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &b){
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (out);
}
