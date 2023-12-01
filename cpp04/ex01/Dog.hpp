#if !defined(DOG_HPP)
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
protected:

private:
	Brain *brain;
public:
	Dog();
	Dog(const Dog &ref);
	Dog	&operator=(Dog const &ref);
	~Dog();
	void makeSound()const;
};

#endif
