#include "AForm.hpp"

AForm::AForm() : _name("Aform66"), _signed(false), _gradeSign(5), _gradeExecute(5)
{
	std::cout << "AForm default constructor called" << std::endl;
	return ;
}

AForm::AForm(std::string name, int gradeSign, int gradeExecute) : _name(name), _signed(false), _gradeSign(_checkGrade(gradeSign)), _gradeExecute(_checkGrade(gradeExecute))
{
	std::cout << "AForm " << name << ", parameter constructor called" << std::endl;
	return ;
}

AForm::AForm(const AForm& copy) : _name(copy.getName()), _signed(copy.getSigned()), _gradeSign(_checkGrade(copy.getGradeSign())), _gradeExecute(_checkGrade(copy.getGradeExecute()))
{
	std::cout << "AForm " << copy.getName() << ", copy constructor called" << std::endl;
	*this = copy;
	return ;
}

AForm::~AForm()
{
	std::cout << "AForm " << _name << ", destructor called" << std::endl;
	return ;
}

AForm &AForm::operator=(AForm const &copy)
{
	std::cout << "AForm " << copy.getName() << ", copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		const_cast<std::string&>(this->_name) = copy.getName();
		this->_signed = copy.getSigned();
		const_cast<int&>(this->_gradeSign) = _checkGrade(copy.getGradeSign());
		const_cast<int&>(this->_gradeExecute) = _checkGrade(copy.getGradeExecute());
	}
	return (*this);
}

void	AForm::beSigned(Bureaucrat const& vorgon)
{
	if (vorgon.getGrade() > (int)_gradeSign)
		throw AForm::GradeTooLowException();
	if (_signed)
		throw AForm::AlreadySignedException();
	_signed = true;
	std::cout << this->_name << " signed by " << vorgon.getName() << std::endl;
}

bool	AForm::getSigned(void) const
{
	return (_signed);
}

int	AForm::getGradeSign(void) const
{
	return(_gradeSign);
}

int	AForm::getGradeExecute(void) const
{
	return(_gradeExecute);
}

std::string AForm::getName(void) const
{
	return (_name);
}

int	AForm::_checkGrade(int const grade) {
	if (grade < MAX_GRADE)
		throw AForm::GradeTooHighException();
	if (grade > MIN_GRADE)
		throw AForm::GradeTooLowException();
	return grade;
}

void	AForm::_checkExecute(Bureaucrat const& vorgon)
{
	if (this->getSigned() == false)
		throw AForm::FormNotSignException();
	if (vorgon.getGrade() > this->getGradeExecute())
		throw AForm::NoPermissionException();
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Grade Too High Exception");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Grade Too Low Exception");
}

const char* AForm::AlreadySignedException::what() const throw() {
	return ("Already Signed Exception");
}

const char* AForm::FormNotSignException::what() const throw() {
	return ("There Is No Signature Exception");
}

const char* AForm::NoPermissionException::what() const throw() {
	return ("Executor Doesn't Have Permission Exception");
}

std::ostream &operator<<(std::ostream &outputFile, AForm const &Aform)
{
	outputFile	<< "AForm: " << Aform.getName() << " is " << (Aform.getSigned() ? "signed" : "not signed")
			<< ", grade needed to sign " << Aform.getGradeSign()
			<< ", grade needed to execute " << Aform.getGradeExecute() << "." << std::endl;
	return (outputFile);
}
