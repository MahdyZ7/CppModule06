/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:49:01 by ayassin           #+#    #+#             */
/*   Updated: 2022/12/02 19:30:59 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

int validity_check(const char* str);

int main(int argc, char **argv)
{
	try
	{
		int check1 = 0;
		if (argc != 2)
			throw std::invalid_argument("wrong number of arguments");
		check1 = validity_check(argv[1]);
		if (check1 == 3)
		{
			std::cout << "char: " << static_cast<char>(argv[1][0]) << std::endl;
			std::cout << "int: " << static_cast<int>(argv[1][0]) << std::endl;	
			std::cout << "float: " << static_cast<float>(argv[1][0]) << ".0f" << std::endl;
			std::cout << "double: " << static_cast<double>(argv[1][0]) << ".0" << std::endl;
		}
		else
		{
			print_char(argv[1]);
			print_int(argv[1], check1 < 10);
			print_float(argv[1]);
			print_double(argv[1]);
		}
		return (0);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Inavlid input: " << e.what() << '\n';
		return (-1);
	}
}

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
	if (str[0] >= 32 && str[0] < 127 && str[1] == 0 )
	{
		std::cout << "32\n";
		return 3;
	}
	for (size_t i = 0; str[i]; ++i)
	{
		// if (str[i] == '.' && !isdigit(str[i+1]))
		// 	throw std::invalid_argument("decimal point must be followed by a digit");
		if (str[i] == '.')
			++dec_points;
		else if (str[i] == 'f' && str[i + 1] != 0)
			throw std::invalid_argument("f must be the last character");
		else if (str[i] == 'e' &&
				!(str[i + 1]) )
			throw std::invalid_argument("e must be followed by a digit");
		else if (str[i] == 'e')
			++e_count;
		else if ((str[i] == '+' || str[i] == '-') && !((i == 0 || str[i - 1] == 'e') && str[i + 1]))
			throw std::invalid_argument("sign must be placed in a valid position");
		else if (!(str[i] == 'f' || str[i] == '-' || str[i] == '+' || isdigit(str[i])))
			throw std::invalid_argument("invalid character");
		else if (str[i] == 'f')
			++f_count;
		if (dec_points > 1 || e_count > 1)
			throw std::invalid_argument("invalid number of decimal points or e");
	}
	if (f_count && (strtod(str, NULL) == INFINITY || strtod(str, NULL) == -INFINITY || 
			static_cast<double>(static_cast<float>(strtod(str, NULL))) != strtod(str, NULL)))
		throw std::invalid_argument("float overflow");
	else if (dec_points || e_count)
		return 2;
	return (0);
}