#include <iostream>
#include <stdlib.h>
#include <string>

int validity_check(const char* str){
	int dec_points = 0;
	int e_count = 0;
	int f_count = 0;

	const std::string sp_cases[6] = {"nan", "inf", "-inf", "nanf", "inff", "-inff"};
	for (int i = 0; i < 6; ++i)
	{
		if (str == sp_cases[i])
			return ((i % 3) * 10);
	}
	for (size_t i = 0; str[i]; ++i)
	{
		if (str[i] == '.')
			++dec_points;
		else if (str[i] == 'f' && str[i + 1] != 0)
			return (-1);
		else if (str[i] == 'e' &&
				!(str[i + 1]) )
			return (-2);
		else if (str[i] == 'e')
			++e_count;
		else if ((str[i] == '+' || str[i] == '-') && !((i == 0 || str[i - 1] == 'e') && str[i + 1]))
			return (-3);
		else if (!(str[i] == 'f' || str[i] == '-' || str[i] == '+' || isdigit(str[i])))
			return (-4);
		else if (str[i] == 'f')
			++fcount;
		if (dec_points > 1 || e_count > 1)
			return (-5);
	}
	if (fcount)
		return 1;
	else if (dec_points || e_count)
		return 2;
	return (0);
}
int main(int argc, char **argv)
{
	int check1 = 0;
	if (argc != 2)
	{
		std::cout << "wrong number of arguments" << std::endl;
		return (0);
	}
	check1 = validity_check(argv[1]);
	if (check1 < 0)
	{
		std::cout << "Invalid input" << check1 <<  std::endl;
		return (0);
	}
	char *temp;
	std::cout << "char: " << static_cast<char>(atoi(argv[1])) << std::endl;
	std::cout << "int: " << static_cast<int>(atoi(argv[1])) << std::endl;
	std::cout << "float: " << static_cast<float>(strtof(argv[1], &temp)) << std::endl;
	std::cout << "double: " << static_cast<double>(strtod(argv[1], &temp)) << std::endl;
	// std::cout << std::stod(argv[1]) << std::endl;
	// for a valid argument: atmost 1 ., atmost 1 f at the end atmost 1 e
	//		nanf, nan, -inf, -inff, inf, inff
	//		check for overflow
	// e+17 and e-17 are valid arguments
	std::cout << atof(argv[1]) << std::endl;
}