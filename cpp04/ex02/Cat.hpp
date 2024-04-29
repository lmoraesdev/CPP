#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"

// Cat Class
class Cat : public AAnimal
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
