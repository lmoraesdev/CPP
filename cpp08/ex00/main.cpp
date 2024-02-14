#include "easyfind.hpp"



int main()
{
	std::vector <int> container(5);
	for (int i = 0; i < 5; i++)
		container[i] = i + 10;

	easyfind(container, 11);
	return 0;
}
