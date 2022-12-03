/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeinfo.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:31:19 by ayassin           #+#    #+#             */
/*   Updated: 2022/12/03 11:07:26 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEINFO_HPP
# define TYPEINFO_HPP

# include <iostream>
# include <exception>
#include<cstdlib>
#include<ctime>

class Base;
Base *generate(void);
void identify(Base *p);
void identify(Base &p);

class Base
{
	public:
		virtual ~Base(void);
};

class A : public Base {
	public:
		A(void);
		virtual ~A(void);
};
class B : public Base {
	public:
		B(void);
		virtual ~B(void);
};
class C : public Base {
	public:
		C(void);
		virtual ~C(void);
};

#endif