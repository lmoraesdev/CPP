#if !defined(FORM_HPP)
# define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include <fstream>



class Bureaucrat;

class Form
{
private:
	std::string const name;
	bool	assigned;
	const int grade_exec;
	const int grade_sign;


public:
	Form(std::string const &name, int _grade_exec, int _grade_sign);
	Form(const Form &ref);
	~Form();
	// Structs
	struct GradeTooHighException : public std::exception
	{
		const char *what() const throw(){
			return ("Grade is too high");
		}
	};

	struct GradeTooLowException : public std::exception
	{
		const char *what() const throw(){
			return ("Grade is too low");
		}
	};
// Getters
	std::string getName()const;
	int getGradeSign()const;
	int getGradeExec()const;
	bool getSigned()const;

// Operators
	Form	operator=(Form const &ref);
	// Form	operator++ (int value);
	// Form	operator-- (int value);
	// Form	&operator++ ();
	// Form	&operator-- ();
// Functions
	void	beSigned(const Bureaucrat &b);
	virtual void execute(Bureaucrat const & executor) const{
		(void) executor;
	};
};

std::ostream	&operator<<(std::ostream &out, const Form &b);

#endif
