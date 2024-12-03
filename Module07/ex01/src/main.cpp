/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/28 14:09:31 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/08/28 14:47:37 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/iter.hpp"
#include <iostream>

static void string_attach(std::string &input)
{
	input.append(" cool");
}
static void double_int(int &num)
{
	num = num * 2;
}

int main(void)
{
	std::size_t len = 6;
	int intArr[6] = {1, 2, 3, 4, 5, 6};
	std::string strArr[6] = {"i", "am", "running", "out", "of", "ideas"};

	::iter(intArr, len, double_int);
	std::cout << "\033[33mPrinting the ints that have been doubled:\033[0m" << std::endl;
	for (std::size_t i = 0; i < len; i++)
	{
		std::cout << intArr[i] << std::endl;
	}
	::iter(strArr, len, string_attach);
	std::cout << "\033[33mPrinting the strings that have \"cool\" attached:\033[0m" << std::endl;
	for (std::size_t i = 0; i < len; i++)
	{
		std::cout << strArr[i] << std::endl;
	}
	return 0;
}