#include  <iostream>
#include  "Dog.hpp"
#include  "Cat.hpp"

int main()
{
	Animal *pets[50];

	for (int i = 0; i < 25; i++){
		pets[i] = new Dog;
		std::cout << "\033[1;32mDog number " << i + 1 << "\033[0;0m" << std::endl;
	}
	for (int i = 25; i < 50; i++){
		pets[i] = new Cat;
		std::cout << "\033[1;32mCat number " << i + 1 << "\033[0;0m" << std::endl;
	}

	for (int i = 0; i < 50; i++){
		std::cout << "\033[1;32mAnimal number " << i + 1 << "\033[0;0m" << std::endl;
		delete pets[i];
	}

}
