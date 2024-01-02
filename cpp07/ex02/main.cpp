#include	"Array.hpp"

int main (void){
	Array<int> number(5);

	for (int i = 0; i < number.size(); i++)
		number[i] = i + 1;
	for (int i = 0; i < number.size(); i++)
		std::cout << number[i] << std::endl;

}
