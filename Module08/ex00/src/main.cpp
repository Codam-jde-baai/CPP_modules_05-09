/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/28 14:09:31 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/10/17 14:18:48 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main(void)
{

	try
	{
		std::vector<int> test_last({5, 0, 2, 45000, 42});
		std::vector<int> test_middle({5, 0, 42, 45000, 2});
		std::vector<int> test_first({42, 0, 10376, 45000, 2});
		std::vector<int> test_missing({42545, 0, 10376, 45000, 2});
		std::vector<int>::iterator out;

		std::cout << "\033[033mUsing std::vector for the template:\033[0m" << std::endl;
		std::cout << "\033[032mAll of these should return 42:\033[0m" << std::endl;
		out = easyfind(test_last, 42);
		std::cout << *out << std::endl;
		out = easyfind(test_middle, 42);
		std::cout << *out << std::endl;
		out = easyfind(test_first, 42);
		std::cout << *out << std::endl;
		std::cout << "\033[031mShould be missing value:\033[0m" << std::endl;
		out = easyfind(test_missing, 42);
		std::cout << *out << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "\033[033mUsing std::list for the template:\033[0m" << std::endl;
		std::list<int> test({5, 0, 2, 45000, 42});
		std::list<int> test_missing({42545, 0, 10376, 45000, 2});
		std::list<int>::iterator out;
		std::cout << "\033[032mTest should return 45000:\033[0m" << std::endl;
		out = easyfind(test, 45000);
		std::cout << *out << std::endl;
		std::cout << "\033[031mTest should return missing:\033[0m" << std::endl;
		out = easyfind(test_missing, 42);
		std::cout << *out << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}