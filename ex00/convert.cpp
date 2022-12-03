/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:49:01 by ayassin           #+#    #+#             */
/*   Updated: 2022/12/03 16:11:46 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

int validity_check(const char* str);

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw std::invalid_argument("wrong number of arguments");
		switch (validity_check(argv[1]))
		{
			case 0:
				print_int(std::atoi(argv[1]));
				break;
			case 1:
				print_float(std::atof(argv[1]));
				break;
			case 2:
				print_double(strtod(argv[1], NULL));
				break;
			case 3:
				print_char(argv[1][0]);
				break;
			default:
				print_spc(argv[1]);
		}
		return (0);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Inavlid input: " << e.what() << '\n';
		return (-1);
	};
}
int validity_check(const char* str){
	int dec_points = 0;
	int e_count = 0;
	int f_count = 0;

	const std::string sp_cases[6] = {"nan", "inf", "-inf", "nanf", "inff", "-inff"};
	for (int i = 0; i < 6; ++i)
	{
		if (str == sp_cases[i])
			return ((i + 1) * 10);
	}
	if ((str[0] >= 32 && str[0] < '0') || (str[0] > '9' && str[0] < 127 && str[1] == 0 ))
		return 3;
	for (size_t i = 0; str[i]; ++i)
	{
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
	if (f_count && !(dec_points + e_count))
		throw std::invalid_argument("f and . must be used together");
	if (f_count && (strtod(str, NULL) == INFINITY || strtod(str, NULL) == -INFINITY ||
			static_cast<float>(strtod(str, NULL)) == INFINITY || static_cast<float>(strtod(str, NULL)) == -INFINITY))
		throw std::invalid_argument("float overflow");
	if (f_count)
		return 1;
	else if (dec_points || e_count)
		return 2;
	else if (static_cast<double>(atoi(str)) != strtod(str, NULL))
		throw std::invalid_argument("Int overflow");
	return (0);
}