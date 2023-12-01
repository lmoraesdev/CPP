#if !defined(ROBOTOMYREQUESTFORM_HPP)
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
protected:
	std::string target;
public:
	RobotomyRequestForm(	std::string _target);
	RobotomyRequestForm(const RobotomyRequestForm &ref);
	RobotomyRequestForm	&operator=(RobotomyRequestForm const &ref);
	~RobotomyRequestForm();
	virtual	void execute(Bureaucrat const & executor) const;
	std::string getTarget()const ;
};


#endif
