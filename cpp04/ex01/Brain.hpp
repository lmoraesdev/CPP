#if !defined(BRAIN_HPP)
#define BRAIN_HPP

#include <iostream>

class Brain
{
protected:
	std::string ideas[100];
public:
	Brain(std::string const &name = "Default_Frag");
	Brain(const Brain &ref);
	Brain	&operator=(Brain const &ref);
	~Brain();
};

#endif // BRAIN_HPP
