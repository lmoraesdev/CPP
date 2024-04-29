#include "Base.hpp"
#include "identify.hpp"

int main(void)
{
    std::srand(std::time(NULL)); // set seed for rand() function

    std::cout << std::endl << "Random Base class generated" << std::endl;
    Base *base = generate();

    std::cout << std::endl << YELLOW << "Identifying the type of the Base class using pointers:" << RESET << std::endl;
    std::cout << "\t" << GREEN;
    identify(base);
    std::cout << RESET;

    std::cout << std::endl << YELLOW << "Identifying the type of the Base class using references:" << RESET << std::endl;
    std::cout << "\t" << GREEN;
    identify(*base);
    std::cout << RESET;

    delete base;
    return (0);
}
