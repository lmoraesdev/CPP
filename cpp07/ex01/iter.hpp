#if !defined(ITER_HPP)
# define ITER_HPP

#include <iostream>

template <typename T> void iter(T *array, int length, void(*exec)(T)){

	for (int i = 0; i < length; i++)
		exec(array[i]);

}

#endif
