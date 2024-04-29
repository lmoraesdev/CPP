#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

# include "Base.hpp"
# include <iostream>
# include <cstdlib>
# include <ctime>

# define RESET		"\e[m"
# define RED		"\e[31m"
# define GREEN		"\e[32m"
# define YELLOW		"\e[33m"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
