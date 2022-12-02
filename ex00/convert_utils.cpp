/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:31:23 by ayassin           #+#    #+#             */
/*   Updated: 2022/12/02 19:31:29 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

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
	long l = static_cast<long>(atof(num));
	int i = static_cast<int>(l);
	std::cout << "int: ";
	if (nrml_case && static_cast<long>(i) == l)
		std::cout << static_cast<int>(l) << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void print_float(char *num)
{
	float f = static_cast<float>(atof(num));
	std::cout << "float: " << f;
	if (static_cast<float>(static_cast<int>(f)) == f && (f < 1000000.0f && f > -1000000.0f))
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void print_double(char *num)
{
	// char *temp;
	double d = static_cast<double>(strtod(num, NULL));
	std::cout << "double: " << d;
	if (static_cast<double>(static_cast<int>(d)) == d && (d < 1000000.0 && d > -1000000.0))
		std::cout << ".0";
	std::cout << std::endl;
}