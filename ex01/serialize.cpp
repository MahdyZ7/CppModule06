/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 08:23:49 by ayassin           #+#    #+#             */
/*   Updated: 2022/12/03 16:18:02 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.hpp"

uintptr_t serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

std::ostream& operator<<(std::ostream& os, const Data *lst)
{
	os << serialize(const_cast<Data *>(lst));
	while(lst)
	{
		os << " -> ";
		os << "n: " << lst->n;
		os << " nxt: " << serialize(lst->nxt);
		lst = lst->nxt;
	}
	return (os);
}

int main(void)
{
	uintptr_t raw = 123456789;
	Data *lst = new Data;
	lst->n = 1;
	lst->nxt = new Data;
	lst->nxt->n = 2;
	lst->nxt->nxt = NULL;
	
	std::cout << "raw: " << raw << std::endl;
	std::cout << "raw to Data and back: " << serialize(deserialize(raw)) << std::endl;
	std::cout << "lst: " <<lst << std::endl;
	std::cout << "serialize(lst): " << serialize(lst) << std::endl;
	std::cout << "Data to uintptr_t and back: " << deserialize(serialize(lst)) << std::endl;
	
	while(lst)
	{
		Data *tmp = lst;
		lst = lst->nxt;
		delete tmp;
	}
	return 0;
}