#if !defined(BUREAUCRAT_HPP)
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	std::string const name;
	int				grade;



public:
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(const Bureaucrat &ref);
	~Bureaucrat();
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

	std::string getName()const;
	int getGrade()const;
// Operators
	Bureaucrat	&operator=(Bureaucrat const &ref);
	Bureaucrat operator++ (int value);
	Bureaucrat operator-- (int value);
	Bureaucrat &operator++ ();
	Bureaucrat &operator-- ();

// Functions
	void	signForm(Form &form);

};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &b);

#endif
