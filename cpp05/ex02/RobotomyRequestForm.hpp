#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm {
private:
	std::string	_target;
public:
	// Constructors and destructor
	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &source);
	virtual ~RobotomyRequestForm(void);

	// Operator overloads
	RobotomyRequestForm	&operator=(const RobotomyRequestForm &source);

	// Member functions
	std::string getTarget(void) const;
	void		execute(Bureaucrat const &executor) const;
};

#endif
