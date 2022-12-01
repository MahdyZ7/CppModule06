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
		if (str[i] == '.' && !isdigit(str[i+1])) // is .12 valid
			return -1;
		else if (str[i] == '.')
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
			++f_count;
		if (dec_points > 1 || e_count > 1)
			return (-5);
	}
	if (f_count)
		return 1;
	else if (dec_points || e_count)
		return 2;
	return (0);
}

void print_char(char *num)
{
	int c = static_cast<int>(atof(num));
	std::cout << "char: ";
	if (c >= 32 && c < 127)
		std::cout << static_cast<char>(atof(num)) << std::endl;
	else if (c >= -128 && c <= 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void print_int(char *num, int nrml_case)
{
	unsigned long c = static_cast<unsigned long>(atof(num));
	std::cout << "int: ";
	if (c < 0xffffffff && nrml_case)
		std::cout << static_cast<int>(atof(num)) << std::endl;
	else
		std::cout << "impossible" << std::endl;
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
	print_char(argv[1]);
	print_int(argv[1], check1 < 10);
	std::cout << "float: " << std::fixed << (static_cast<float>(strtof(argv[1], &temp))) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(strtod(argv[1], &temp)) << std::endl;
	// std::cout << std::stod(argv[1]) << std::endl;
	// for a valid argument: atmost 1 ., atmost 1 f at the end atmost 1 e
	//		nanf, nan, -inf, -inff, inf, inff
	//		check for overflow
	// e+17 and e-17 are valid arguments
	std::cout << static_cast<int>(atof(argv[1])) << std::endl;
}