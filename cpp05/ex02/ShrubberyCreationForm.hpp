#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
private:
	std::string	_target;
public:
	// Constructors and destructor
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &source);
	virtual ~ShrubberyCreationForm(void);

	// Operator overloads
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &source);

	// Member functions
	std::string getTarget(void) const;
	void		execute(Bureaucrat const &executor) const;
	// Exception classes
	class FileNotOpenException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
};

#endif
