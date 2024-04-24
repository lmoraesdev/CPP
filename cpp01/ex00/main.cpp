#include "Zombie.hpp"

int	main(void) {
	std::cout << std::endl;
    std::cout << "TESTING ZOMBIE CLASS USING STACK ALLOCATION" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::endl;
    std::cout << "Calling randomChump()..." << std::endl;

    randomChump("StackZombie");

    std::cout << "randomChump() finished." << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
    std::cout << "TESTING ZOMBIE CLASS USING HEAP ALLOCATION" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << std::endl;
    std::cout << "Calling newZombie()..." << std::endl;

    Zombie* zombie1 = newZombie("HeapZombie");

    std::cout << "newZombie() finished." << std::endl;
	std::cout << std::endl;
    std::cout << "Calling announce() on heap-allocated zombie..." << std::endl;

    zombie1->announce();

    std::cout << "announce() finished." << std::endl;
	std::cout << std::endl;
    std::cout << "Deleting the heap-allocated zombie..." << std::endl;

    delete zombie1;

    std::cout << "Heap-allocated zombie deleted." << std::endl;
	std::cout << std::endl;
    return (0);
}
