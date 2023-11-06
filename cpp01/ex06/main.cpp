#include "Harl.hpp"

int main (int argc, char **argv){

	Harl harl;
	if(argc != 2)
		return 0;
	std::string buffer;
	for (int y = 0; argv[1][y]; y++){
		buffer += toupper(argv[1][y]);
	}
	harl.complain(buffer);
	return (0);
}
