#include  <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <exception>

Base *generate(void){
	int gen;

	srand(time(NULL));
	gen = rand() % 3;
	if (gen == 0)
		return (dynamic_cast<Base *>(new A));
	if (gen == 1)
		return (dynamic_cast<Base *>(new B));
	if (gen == 2)
		return (dynamic_cast<Base *>(new C));
	return (0);
}

void identify(Base* p){
	A *a;
	B *b;
	C *c;

	a = dynamic_cast <A *>(p);
	b = dynamic_cast <B *>(p);
	c = dynamic_cast <C *>(p);
	(void)p;
	if (a != 0)
		std ::cout << "Type A" << std::endl;
	else if (b != 0)
		std ::cout << "Type B" << std::endl;
	else if (c != 0)
		std ::cout << "Type C" << std::endl;
	else
		std ::cout << "Invalid type" << std::endl;

}

void identify(Base& p){

	(void)p;
	try {
		A a = dynamic_cast <A &>(p);
		std ::cout << "Type A" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}

	try {
		B b = dynamic_cast <B &>(p);
		std ::cout << "Type B" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}

	try {
		C c = dynamic_cast <C &>(p);
		std ::cout << "Type C" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
}

int main (void){
	Base *base = generate();

	std :: cout << "identify(Base* p): ";
	identify(base);
	std :: cout << "identify(Base& p): ";
	identify(*base);
	delete base;
	return (0);
}
