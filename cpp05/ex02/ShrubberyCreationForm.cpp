#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target)
: Form("ShrubberyCreationForm", 137 , 145) , target(_target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref)
: Form("ShrubberyCreationForm", 137 , 145) , target(ref.getTarget())
{
	*this = ref;
	std::cout << "ShrubberyCreationForm contructor by copy" << std::endl;
}


ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor of ShrubberyCreationForm " << " called" <<std::endl;
}

ShrubberyCreationForm		&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &ref)
{
	std::cout << "Assignation with operator= called" <<std::endl;
	if (this != &ref)
	{
		*this = ref;
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() >= this->getGradeExec())
		throw ShrubberyCreationForm::Form::GradeTooLowException();
	std::string name = this->getTarget() +"_shrubbery";
	std::ofstream file(name.c_str());
	if (file.is_open())
	{
		file << "    *    " << std::endl;
		file << "   ***   " << std::endl;
		file << "  **o**  " << std::endl;
		file << " *****o* " << std::endl;
		file << "**o******" << std::endl;
		file << "    |    " << std::endl;
	}
}

std::string ShrubberyCreationForm::getTarget()const{
	return (this->target);
}
