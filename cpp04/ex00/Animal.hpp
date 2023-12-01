#if !defined(ANIMAL_HPP)
# define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal(std::string const &name = "Default_Frag");
	Animal(const Animal &ref);
	Animal	&operator=(Animal const &ref);
	virtual ~Animal();
	virtual void makeSound()const;
};

#endif
