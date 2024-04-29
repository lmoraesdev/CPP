#include "iter.hpp"

int main( void ) {
    int a[] = {1, 2, 3, 4, 5};
    std::string b[] = {"one", "two", "three", "four", "five"};

    std::cout << YELLOW << "Printing integers in an array..." << RESET << std::endl;
    ::iter(a, 5, print);
    std::cout << YELLOW << "Printing strings in an array..." << RESET << std::endl;
    ::iter(b, 5, print);
    return (0);
}
