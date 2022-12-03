/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_helper.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:18:27 by ayassin           #+#    #+#             */
/*   Updated: 2022/12/03 16:01:22 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

void print_char(char c)
{
	std::cout << "char: " << static_cast<char>(c) << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;	
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void print_int(int i)
{
	std::cout << "char: ";
	if (i >= 32 && i < 127)
		std::cout << static_cast<char>(i) << std::endl;
	else if (i >= -128 && i <= 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i);
	if (i < 1000000 && i > -1000000)
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double: " << i;
	if (i < 1000000 && i > -1000000)
		std::cout << ".0";
	std::cout << std::endl;
}

void print_float(float f)
{
	std::cout << "char: ";
	if (f >= 32.0f && f < 127.0)
		std::cout << static_cast<char>(f) << std::endl;
	else if (f >= -128.0f && f <= 127.0f)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;
	long l = static_cast<long>(f);
	int i = static_cast<int>(l);
	std::cout << "int: ";
	if (static_cast<long>(i) == l)
		std::cout << static_cast<int>(f) << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "float: " << f;
	if (static_cast<float>(static_cast<int>(f)) == f && (f < 1000000.0f && f > -1000000.0f))
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double: " << f;
	if (static_cast<float>(static_cast<int>(f)) == f && (f < 1000000.0f && f > -1000000.0f))
		std::cout << ".0";
	std::cout << std::endl;
}

void print_double(double d)
{
	std::cout << "char: ";
	if (d >= 32.0 && d < 127.0)
		std::cout << static_cast<char>(d) << std::endl;
	else if (d >= -128.0 && d <= 127.0)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;
	long l = static_cast<long>(d);
	int i = static_cast<int>(l);
	std::cout << "int: ";
	if (static_cast<long>(i) == l)
		std::cout << static_cast<int>(d) << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "float: " << static_cast<float>(d);
	if (static_cast<double>(static_cast<int>(d)) == d && (d < 1000000.0 && d > -1000000.0))
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double: " << d;
	if (static_cast<double>(static_cast<int>(d)) == d && (d < 1000000.0 && d > -1000000.0))
		std::cout << ".0";
	std::cout << std::endl;
}

void print_spc(char *str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (str[4])
	{
		float f = static_cast<float>(atof(str));
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	}
	else
	{
		double d = static_cast<double>(strtod(str, NULL));
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}	
}