#if !defined(DOG_HPP)
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
protected:

public:
	Dog();
	Dog(const Dog &ref);
	Dog	&operator=(Dog const &ref);
	~Dog();
	void makeSound()const;
};

#endif
