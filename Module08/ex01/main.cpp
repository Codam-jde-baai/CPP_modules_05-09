/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/28 14:09:31 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/10/17 14:41:02 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/Span.hpp"
#include <iostream>
#include <climits>

int main(void)
{

	try
	{
		std::cout << "\033[33mAdding too many elements:\033[0m" << std::endl;
		Span crash(2);

		crash.addNumber(-1);
		crash.addNumber(-1);
		crash.addNumber(-1);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "\033[33mNot enough elements for Span:\033[0m" << std::endl;
		Span crash(3);

		crash.addNumber(-1);
		std::cout << "Longest span: " << crash.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "\033[33mNon-crash tests(subject)\033[0m" << std::endl;
		Span test(5);

		std::vector<int> range({6, 3, 17, 9, 11});
		test.addRange(range.begin(), range.end());
		std::cout << "Shortest span: " << test.shortestSpan() << std::endl;
		std::cout << "Longest span: " << test.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "\033[33mNon-crash tests(MAX)\033[0m" << std::endl;
		Span test(4);

		test.addNumber(INT_MAX);
		test.addNumber(INT_MIN);
		// test.addNumber(0);
		// test.addNumber(0);
		test.printSpan();
		std::cout << "Shortest span: " << test.shortestSpan() << std::endl;
		std::cout << "Longest span: " << test.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "\033[33mUsing testing functions\033[0m" << std::endl;
		Span test(10);

		test.floodSpan();
		test.printSpan();
		std::cout << "Shortest span: " << test.shortestSpan() << std::endl;
		std::cout << "Longest span: " << test.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}