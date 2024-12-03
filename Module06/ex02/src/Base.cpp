/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Base.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/28 11:53:34 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/08/28 12:43:25 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

// general functions

/**
 * @warning returns a heap allocated pointer
 * @return if return value == nullptr allocation failed
 */
Base *generate(void)
{
	Base *out = nullptr;
	srand(time(NULL) + rand()); // + rand() to make the seed different on multiple func calls
	int random = rand() % 3 + 1;
	switch (random)
	{
	case 1:
		out = new A;
		break;
	case 2:
		out = new B;
		break;
	case 3:
		out = new C;
		break;
	}
	return (out);
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
	{
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B *>(p))
	{
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C *>(p))
	{
		std::cout << "C" << std::endl;
	}
	else
	{
		std::cout << "The pointer passed does not use class A, B or C" << std::endl;
	}
}

// not allowed to use a pointer here
void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a; // avoiding unused error
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::bad_cast &)
	{
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b; // avoiding unused error
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::bad_cast &)
	{
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::bad_cast &)
	{
	}
	std::cout << "Unknown type" << std::endl;
}
