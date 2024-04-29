#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

// Abstract Animal Class
class AAnimal
{
protected:
	std::string _type;
	// Non instantiable class - protected methods
	// Constructors and destructor
	AAnimal(void);
	AAnimal(std::string type);
	AAnimal(const AAnimal& other);
	virtual ~AAnimal(void);
	// Operator overloads
	AAnimal& operator=(const AAnimal& other);
public:
	// Member functions
	std::string getType(void) const;
	virtual void makeSound(void) const = 0; // Pure virtual function
};

#endif
