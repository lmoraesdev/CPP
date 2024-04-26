#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

// Dog Class
class Dog : public Animal
{
public:
	// Constructors and destructor
	Dog(void);
	Dog(const Dog& other);
	virtual ~Dog(void);

	// Operator overloads
	Dog	&operator=(const Dog& other);

	// Member functions
	virtual void	makeSound(void) const;
};

#endif
