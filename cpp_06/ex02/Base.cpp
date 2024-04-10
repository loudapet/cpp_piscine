#include "Base.hpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouda <plouda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:29:43 by plouda            #+#    #+#             */
/*   Updated: 2024/04/09 12:29:44 by plouda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

Base::~Base()
{
	return ;
}

Base *generate(void)
{
	srand(time(0));
	switch (rand() % 3 + 1)
	{
		case 1:
			return (new A);
		case 2:
			return (new B);
		case 3:
			return (new C);
		default:
			return (NULL);
	}
}

void identify(Base *ptr)
{
	std::cout << "Identified pointer: ";
	if (dynamic_cast<A*>(ptr) != NULL)
		std::cout << "A";
	else if (dynamic_cast<B*>(ptr) != NULL)
		std::cout << "B";
	else if (dynamic_cast<C*>(ptr) != NULL)
		std::cout << "C";
	else
		std::cout << "unidentified";
	std::cout << std::endl;
}

void identify(Base &ref)
{
	try
	{
		(void)dynamic_cast<A&>(ref);
		std::cout << "Identified reference: A" << std::endl;
	}
	catch(const std::bad_cast& e){}

	try
	{
		(void)dynamic_cast<B&>(ref);
		std::cout << "Identified reference: B" << std::endl;
	}
	catch(const std::bad_cast& e){}

	try
	{
		(void)dynamic_cast<C&>(ref);
		std::cout << "Identified reference: C" << std::endl;
	}
	catch(const std::bad_cast& e){}
	
}
