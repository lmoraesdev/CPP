#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	std::string	_target;
public:
	// Constructors and destructor
	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &source);
	virtual ~PresidentialPardonForm(void);

	// Operator overloads
	PresidentialPardonForm	&operator=(const PresidentialPardonForm &source);

	// Member functions
	std::string getTarget(void) const;
	void		execute(Bureaucrat const &executor) const;
};

#endif
