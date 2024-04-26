#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	// Constructors and destructor
	WrongCat(void);
	WrongCat(const WrongCat& other);
	virtual ~WrongCat(void);

	// Operator overloads
	WrongCat	&operator=(const WrongCat &other);
};

#endif
