#include  <iostream>
#include  "Animal.hpp"
#include  "Dog.hpp"
#include  "Cat.hpp"

int main (void){

	const Animal *animal = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();


	animal->makeSound();
	dog->makeSound();
	cat->makeSound();
	delete animal;
	delete dog;
	delete cat;
	return (0);
}
