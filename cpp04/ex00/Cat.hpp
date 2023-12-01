#if !defined(CAT_HPP)
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
protected:

public:
	Cat();
	Cat(const Cat &ref);
	Cat	&operator=(Cat const &ref);
	~Cat();
	void makeSound()const;
};

#endif
