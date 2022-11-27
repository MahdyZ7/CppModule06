#include <iostream>
#include <stdlib.h>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "wrong number of arguments" << std::endl;
		return 1;
	}
	// std::cout << std::stof(argv[1]) << std::endl;
	// for a valid argument: atmost one ., atmost one f at the end
	//		nanf, nan, -inf, -inff, inf, inff
	std::cout << atof(argv[1]) << std::endl;
}