#if !defined(PRESIDENTIALPARDONFORM)
# define PRESIDENTIALPARDONFORM

#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
protected:
	std::string target;
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &ref);
	PresidentialPardonForm	&operator=(PresidentialPardonForm const &ref);
	~PresidentialPardonForm();
	virtual	void execute(Bureaucrat const & executor) const;
	std::string getTarget()const ;
};

#endif
