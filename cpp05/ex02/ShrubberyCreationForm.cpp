#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) , _target("Undefined")
{
	std::cout << "Shrubbery Creation Form default constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "Shrubbery Creation Form target parameter constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & copy) : AForm("ShrubberyCreationForm", 145, 137)
{
	*this = copy;
	std::cout << "Shrubbery Creation Form, copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Creation Form, destructor called" << std::endl;
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( ShrubberyCreationForm const &copy )
{
	std::cout << "Shrubbery Creation Form, copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->_target = copy.getTarget();
	}
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (!this->getSigned())
		throw AForm::FormNotSignException();
	else if (this->getGradeExecute() < executor.getGrade())
		throw AForm::GradeTooLowException();
	else
	{
		std::string		fileName;
		std::ofstream	file;

		fileName = this->getTarget() + "_shrubbery";
		file.open(fileName.c_str());
		if (!file.is_open())
			return ;
		file << "TREE IN ASCII\n"
			<< "               _{\\ _{\\{\\/}/}/}__\n"
			<< "              {/{/\\}{/{/\\}(\\}{/\\} _\n"
			<< "             {/{/\\}{/{/\\}(_)\\}{/{/\\}  _\n"
			<< "          {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n"
			<< "         {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n"
			<< "        _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n"
			<< "       {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\n"
			<< "       _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}\n"
			<< "      {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}\n"
			<< "       {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n"
			<< "        {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n"
			<< "       {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\n"
			<< "        {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}\n"
			<< "          {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n"
			<< "           (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)\n"
			<< "             {/{/{\\{\\/}{/{\\{\\{\\(_)/}\n"
			<< "              {/{\\{\\{\\/}/}{\\{\\\\}/}\n"
			<< "               {){/ {\\/}{\\/} \\}\\}\n"
			<< "               (_)  \\.-'.-/\n"
			<< "           __...--- |'-.-'| --...__\n"
			<< "    _...--'   .-'   |'-.-'|  ' -.  --..__\n"
			<< "  -.    ' .  . '    |.'-._| '  . .  '   \n"
			<< "  .  '-  '    .--'  | '-.'|    .  '  . '\n"
			<< "           ' ..     |'-_.-|\n"
			<< "   .  '  .       _.-|-._ -|-._  .  '  .\n"
			<< "               .'   |'- .-|   '.\n"
			<< "   ..-'   ' .  '.   `-._.-'   .'  '  - .\n"
			<< "    .-' '        '-._______.-'     '  .\n";
		file.close();
	}
}

const char* ShrubberyCreationForm::CreateFileException::what() const throw()
{
	return ("Something went wrong while creating the shrubbery");
}
