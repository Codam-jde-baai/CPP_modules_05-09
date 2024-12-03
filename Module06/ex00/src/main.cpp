/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/29 15:38:17 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/08/28 10:34:42 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/ScalarConverter.hpp"
#include <cstring>

/*
ScalarConverter uses static cast and std::stoi/stof/stod
*/

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Please input 1 int, char, float or double to convert" << std::endl;
		return (EXIT_FAILURE);
	}
	if (std::string(av[1]) == "test")
	{
		std::string input;
		while (true)
		{
			std::cout << "\033[33mEnter a value (or press Enter to exit): \033[0m";
			std::getline(std::cin, input);
			if (input.empty())
				break;
			ScalarConverter::convert(input);
		}
		return (EXIT_SUCCESS);
	}
	else
	{

		ScalarConverter::convert(av[1]);
		return (EXIT_SUCCESS);
	}
}
