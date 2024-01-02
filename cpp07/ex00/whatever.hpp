#if !defined(WHATEVER_HPP)
# define WHATEVER_HPP

#include <iostream>

template <typename T> void swap(T &first, T &second){
	T holder;

	holder = first;
	first = second;
	second = holder;
}

template <typename T> T min(T first, T second){
	if (first < second)
		return(first);
	return (second);
}

template <typename T> T max(T first, T second){
	if (first > second)
		return(first);
	return (second);
}

#endif
