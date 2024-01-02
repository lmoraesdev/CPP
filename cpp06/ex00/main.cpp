#include "Conv.hpp"

int main(int argc, char const **argv)
{

	if (argc != 2)
		return (0);

	Conv conv(argv[1]);

	conv.parse();
	return 0;
}
