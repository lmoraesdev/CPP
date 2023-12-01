#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(	std::string _target)
: Form("PresidentialPardonForm", 5 , 25) , target(_target)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref)
: Form("PresidentialPardonForm", 5 , 25) , target(ref.getTarget())
{
	*this = ref;
	std::cout << "PresidentialPardonForm contructor by copy" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor of PresidentialPardonForm " << " called" <<std::endl;
}

PresidentialPardonForm		&PresidentialPardonForm::operator=(PresidentialPardonForm const &ref)
{
	std::cout << "Assignation with operator= called" <<std::endl;
	if (this != &ref)
	{
		*this = ref;
	}
	return *this;
}

std::string PresidentialPardonForm::getTarget()const {
	return (this->target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() >= this->getGradeExec())
		throw PresidentialPardonForm::Form::GradeTooLowException();
	std::cout << "Informs that " << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
