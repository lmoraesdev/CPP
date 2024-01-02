#if !defined(ARRAY_HPP)
# define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
private:
	T *array;
	int _size;
public:
// Constructors
	Array(/* args */){
		this->_size = 0;
	}
	Array(unsigned int n){
		this->array = new T[n];
		this->_size = n;
	}
	Array(Array &copy){
		this->array = new T[copy.size()];
		this->_size = copy.size();
		for (int i = 0; i < this->_size; i++)
			this->array[i] = copy[i];
	}

// Getters
	int	size(){
		return (this->_size);
	}

// Operators
	Array		&operator=(Array const &ref){
		this->array = new T[ref.size()];
		this->_size = ref.size();
		for (int i = 0; i < this->_size; i++)
			this->array[i] = ref[i];
		return (*this);
	}

	T		&operator[](int index){
		if (index < 0 || index >= this->_size)
			throw Array::InvalidIndex();
		return (this->array[index]);
	}

// 	Exception
struct InvalidIndex : public std::exception
	{
		const char *what() const throw(){
			return ("Index is outside array's bouderies");
		}
	};


// Destructors
	~Array(){
		delete[] this->array;
	}
};


#endif
