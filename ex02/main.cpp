/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 10:50:47 by ayassin           #+#    #+#             */
/*   Updated: 2022/12/03 11:20:36 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "typeinfo.hpp"

int main()
{
	{
		Base *a = new A;
		Base *b = new B;
		Base *c = new C;
		Base *d = new Base;

		delete a;
		delete b;
		delete c;
		delete d;
	}
	std::cout << std::endl;
	{
		srand(time(0));
		Base *p[10];
		for(int i = 0; i < 10; i++)
			p[i] = generate();
		for(int i = 0; i < 10; i++)
			identify(p[i]);
		std::cout << std::endl;
		for(int i = 0; i < 10; i++)
			identify(*(p[i]));
		for (int i = 0; i < 10; i++)
			delete p[i];
	}
	return (0);
}