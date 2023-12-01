#if !defined(SHRUBBERTCREATIONFORM_HPP)
# define SHRUBBERTCREATIONFORM_HPP

#include <iostream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
protected:
	std::string target;
public:
	ShrubberyCreationForm(	std::string _target);
	ShrubberyCreationForm(const ShrubberyCreationForm &ref);
	ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &ref);
	~ShrubberyCreationForm();
	virtual	void execute(Bureaucrat const & executor) const;
	std::string getTarget()const;
};

#endif
