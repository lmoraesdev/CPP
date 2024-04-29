#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
protected:
	std::string _type;
public:
	// Constructors and destructor
	WrongAnimal(void);
	WrongAnimal(std::string wrongAnimal_type);
	WrongAnimal(const WrongAnimal& other);
	virtual ~WrongAnimal(void);

	// Operator overloads
	WrongAnimal	&operator=(const WrongAnimal &other);

	// Member functions
	std::string	getType(void) const;
	void		makeSound(void) const;
};

#endif
