/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeinfo.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:33:41 by ayassin           #+#    #+#             */
/*   Updated: 2022/12/03 11:08:30 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "typeinfo.hpp"

Base::~Base(void) {
	std::cout << "Base destructor called" << std::endl;
};
A::A(void) {
	std::cout << "A is created" << std::endl;
};
B::B(void) {
	std::cout << "B is created" << std::endl;
};
C::C(void) {
	std::cout << "C is created" << std::endl;
};
A::~A(void) {
	std::cout << "A is destroyed" << std::endl;
};
B::~B(void) {
	std::cout << "B is destroyed" << std::endl;
};
C::~C(void) {
	std::cout << "C is destroyed" << std::endl;
};
Base *generate(void)
{
	int i = rand() % 3;
	if (i == 0)
		return (new A);
	else if (i == 1)
		return (new B);
	else
		return (new C);
}

void identify(Base *p)
{
	try
	{
		void(dynamic_cast<A&>(*p));
		std::cout << "Class is of type A" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{}
	try
	{
		void(dynamic_cast<B&>(*p));
		std::cout << "Class is of type B" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{}
	try
	{
		void(dynamic_cast<C&>(*p));
		std::cout << "Class is of type C" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
		std::cout << "Class is of Base type" << '\n';
	}
}

void identify(Base &p)
{
	try
	{
		void(dynamic_cast<A&>(p));
		std::cout << "Class is of type A" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{}
	try
	{
		void(dynamic_cast<B&>(p));
		std::cout << "Class is of type B" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{}
	try
	{
		void(dynamic_cast<C&>(p));
		std::cout << "Class is of type C" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
		std::cout << "Class is of Base type" << '\n';
	}
}