/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 11:47:20 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/10/10 14:53:46 by juliusdebaa   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// using std::stack

#include "../inc/RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "No input, please provide RPN input with max 1 digit per number" << std::endl;
		return (1);
	}
	try
	{
		RPN calculator;
		int out = calculator.process_input(av[1]);
		std::cout << out << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << "Error" << std::endl; // simple error statement cause we cant have nice things :/
		// std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return (0);
}
