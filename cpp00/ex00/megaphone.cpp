#include <iostream>
#include <cstring>

int main(int argc, char **argv)
{
	std::string buffer;

	if (argc < 2){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int x = 1; argv[x]; x++){
		for (int y = 0; argv[x][y]; y++){
			buffer += toupper(argv[x][y]);
		}
	}
	std::cout << buffer << std::endl;
    return 0;
}
