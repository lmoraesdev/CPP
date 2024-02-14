#if !defined(MUTANTSTACK_HPP)
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <class T>
class MutantStack : public std::stack<T>
{
protected:

public:
	typedef typename std::deque<T>::iterator iterator;
	MutantStack(){

	}
	MutantStack(const MutantStack &ref){

	}
	MutantStack	&operator=(MutantStack const &ref){

	}
	~MutantStack(){

	}

	iterator begin(){
		return (this->c.begin());
	}

	iterator end(){
		return (this->c.end());
	}
};

#endif
