#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string	_name;
		bool		_signed;
		int const	_gradeSign;
		int const	_gradeExecute;
		int			_checkGrade(int const grade);
	public:
		AForm();
		AForm(std::string name, int gradeSign, int gradeExecute);
		AForm(const AForm& copy);
		virtual ~AForm();
		AForm& operator=(AForm const& b);

		std::string		getName() const;
		bool			getSigned() const;
		int				getGradeSign() const;
		int				getGradeExecute() const;
		void			beSigned(Bureaucrat const& vorgon);
		virtual void	execute(Bureaucrat const& executor) const = 0;
		void			_checkExecute(Bureaucrat const& vorgon);

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
		class FormNotSignException: public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};
		class NoPermissionException: public std::exception {
			public:
				virtual const char	*what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &output, AForm const &form);

#endif
