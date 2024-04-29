#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

// Cat Class
class Cat : public Animal
{
private:
	Brain	*_brain;
public:
	// Constructors and destructor
	Cat(void);
	Cat(const Cat& other);
	virtual ~Cat(void);

	// Operator overloads
	Cat	&operator=(const Cat& other);

	// Member functions
	virtual void	makeSound(void) const;
};

#endif
