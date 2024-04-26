#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <sstream>
# include "Brain.hpp"

// Animal Class
class Animal
{
protected:
	std::string _type;
public:
	// Constructors and destructor
	Animal(void);
	Animal(std::string animal_type);
	Animal(const Animal& other);
	virtual ~Animal(void);

	// Operator overloads
	Animal	&operator=(const Animal& other);

	// Member functions
	std::string		getType(void) const;
	virtual void	makeSound(void) const;
};

#endif
