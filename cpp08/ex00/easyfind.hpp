#if !defined(EASYFIND_HPP)
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <exception>

struct NotFound : public std::exception
{
	const char *what() const throw(){
		return ("Target not found");
	}
};

template <typename T> void easyfind(T container, int index){
	typename T::iterator iter = container.begin();
	while (iter != container.end()){
		if (*iter == index){
			std::cout << *iter << std::endl;
			return ;
		}
		iter++;
	}
	throw NotFound();
}


#endif
