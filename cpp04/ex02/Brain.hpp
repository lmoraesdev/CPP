#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <sstream>

class Brain
{
private:
	std::string _ideas[100];
public:
	// Constructors and destructor
	Brain(void);
	Brain(const Brain &source);
	~Brain(void);

	// Operator overloads
	Brain	&operator=(const Brain &other);

	// Member functions
	std::string	*getIdeas(void);
};

#endif
