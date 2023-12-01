#if !defined(AMATERIA_HPP)
# define AMATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria
{
protected:
	std::string type;
public:
	AMateria(std::string const &type);
	AMateria(const AMateria &ref);
	AMateria	&operator=(AMateria const &ref);
	virtual ~AMateria();
	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif
