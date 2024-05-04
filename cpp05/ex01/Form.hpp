#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool			_signed;
		int const		_gradeSign;
		int const		_gradeExecute;
		int				_checkGrade(int const grade);
	public:
		Form();
		Form(std::string name, int gradeSign, int gradeExecute);
		Form(const Form& copy);
		~Form();
		Form& operator=(Form const& b);

		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeSign() const;
		int			getGradeExecute() const;
		void		beSigned(Bureaucrat &vorgon);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};
		class AlreadySignedException: public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &output, Form const &form);

#endif
