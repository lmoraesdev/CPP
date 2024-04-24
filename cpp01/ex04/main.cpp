#include "FileReplacer.hpp"

int	main(int argc, char **argv)
{
	try {
		if (argc != 4) {
			throw std::runtime_error(RED + "Error: wrong number of arguments." + RESET);
		}
		FileReplacer(argv[1], argv[2], argv[3]);
		return (0);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
}
