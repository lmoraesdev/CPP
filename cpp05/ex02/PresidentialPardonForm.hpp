#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target );
		PresidentialPardonForm(PresidentialPardonForm const & copy);
		~PresidentialPardonForm();

		PresidentialPardonForm	&operator=(PresidentialPardonForm const& copy);

		void		execute(Bureaucrat const &executor) const;
		std::string	getTarget() const;

		class CreateFileException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif
