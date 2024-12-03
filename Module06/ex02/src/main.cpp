/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/29 15:38:17 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/09/19 12:26:36 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"

#include <stdlib.h>
#include <time.h>
#include <iostream>

// dynamic cast exercise

int main(void)
{
	Base *test1 = generate();
	if (!test1)
	{
		std::cerr << "test1: generate failed to allocate memory" << std::endl;
		return 1;
	}
	Base *test2 = generate();
	if (!test2)
	{
		delete test1;
		std::cerr << "test2: generate failed to allocate memory" << std::endl;
		return 1;
	}
	Base *test3 = generate();
	if (!test3)
	{
		delete test1;
		delete test2;
		std::cerr << "test3: generate failed to allocate memory" << std::endl;
		return 1;
	}

	std::cout << "\033[33mTest pointers 1,2,3:\033[0m" << std::endl;
	identify(test1);
	identify(test2);
	identify(test3);
	std::cout << "\033[33mTest references 1,2,3:\033[0m" << std::endl;
	identify(*test1);
	identify(*test2);
	identify(*test3);

	delete test1;
	delete test2;
	delete test3;

	return (0);
}
