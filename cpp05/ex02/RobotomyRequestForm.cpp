#include "RobotomyRequestForm.hpp"
#include <cstdlib>
RobotomyRequestForm::RobotomyRequestForm(std::string _target)
: Form("RobotomyRequestForm", 45 , 72) , target(_target)
{
	srand(time(NULL));
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref)
: Form("RobotomyRequestForm", 45 , 72) , target(ref.getTarget())
{
	*this = ref;
	srand(time(NULL));
	std::cout << "RobotomyRequestForm contructor by copy" << std::endl;
}


RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor of RobotomyRequestForm " << " called" <<std::endl;
}

RobotomyRequestForm		&RobotomyRequestForm::operator=(RobotomyRequestForm const &ref)
{
	std::cout << "Assignation with operator= called" <<std::endl;
	if (this != &ref)
	{
		*this = ref;
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() >= this->getGradeExec())
		throw RobotomyRequestForm::Form::GradeTooLowException();

	if (rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;

}

std::string RobotomyRequestForm::getTarget()const {
	return (this->target);
}
