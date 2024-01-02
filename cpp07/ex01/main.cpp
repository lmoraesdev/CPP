#include	"iter.hpp"

void toUpper(char c)
{
	unsigned char	i;

	i = c;
	if (i >= 'a' && i <= 'z')
		i = i - 32;
	std::cout << i << "\n";

}

int main (void){
	std::string string("abc");

	iter(const_cast<char *>(string.c_str()), string.length(), toUpper);

}
