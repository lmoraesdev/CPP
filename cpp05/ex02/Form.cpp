#include "Form.hpp"

Form::Form(std::string const &name, int _grade_exec, int _grade_sign)
: name(name) , grade_exec(_grade_exec), assigned(false), grade_sign(_grade_sign)
{
	if (_grade_exec < 1 || _grade_sign < 1)
		throw Form::GradeTooHighException();
	else if (_grade_exec > 150 || _grade_sign > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form &ref)
: name(ref.getName()), assigned(ref.getSigned()), grade_exec(ref.getGradeExec()), grade_sign(ref.getGradeSign())
{
	if (this->grade_exec < 1 || this->grade_sign < 1)
		throw Form::GradeTooHighException();
	else if (this->grade_exec > 150 || this->grade_sign > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form contructor by copy" << std::endl;
}

Form::~Form()
{
	std::cout << "Destructor of Form " << " called" <<std::endl;
}

Form		Form::operator=(Form const &ref)
{
	this->assigned = ref.getSigned();
	std::cout << "Assignation with operator= called" <<std::endl;
	return *this;
}


std::string Form::getName()const{
	return (this->name);
}

int Form::getGradeExec()const{
	return (this->grade_exec);
}

bool Form::getSigned()const{
	return (this->assigned);
}

int Form::getGradeSign()const{
	return (this->grade_sign);
}


void	Form::beSigned(const Bureaucrat &b){
	if (b.getGrade() <= this->getGradeSign())
		this->assigned = true;
	else
		throw Form ::GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &out, const Form &b){
	out << b.getName() << " form : \nGrade to exec: " << b.getGradeExec() << std::endl;
	out << "Grade to sign: " << b.getGradeSign() << std::endl;
	return (out);
}
