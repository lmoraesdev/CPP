#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

// Macros
# define RESET		"\e[m"
# define RED		"\e[31m"
# define GREEN		"\e[32m"
# define YELLOW		"\e[33m"

// Function template for iterating over an array of any type
template <typename T>
void	iter(T *array, size_t length, void (*f)(T const &)) {
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

// Function template for printing any type of data
template <typename T>
void	print(T const &i) {
    std::cout << i << std::endl;
}

#endif
