/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 11:47:20 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/12/03 13:26:17 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// using std::map

/**
 * steps:
 * store data.csv in class
 * read input.txt line by line
 * function processes line, providing error codes
 * parsed dates&value get used to print.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include "../inc/BitcoinExchange.hpp"

/**
 * @brief processes lines from input.txt and prints output
 */
void process_line(std::string line, BitcoinExchange data)
{
	try
	{
		std::istringstream ss(line);
		std::string s_date, s_value;
		if (std::getline(ss, s_date, '|') && std::getline(ss, s_value))
		{
			s_date.erase(std::remove_if(s_date.begin(), s_date.end(), ::isspace),
						 s_date.end());
			s_value.erase(std::remove_if(s_value.begin(), s_value.end(), ::isspace),
						  s_value.end());
		}
		else
		{
			std::cout << ("Error: bad input => " + s_date) << std::endl;
			return;
		}
		s_time date = split_date(s_date);
		float value = std::stof(s_value);
		if (value < 0)
			throw std::out_of_range("not a positive number.");
		if (value >= 2147483648.0f)
			throw std::out_of_range("too large a number.");
		float rate = data.getRate(date);
		std::cout << s_date << " => " << value << " = " << std::setprecision(2) << (rate * value) << std::endl;
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "No input file, please provide input.txt" << std::endl;
		return (1);
	}
	try
	{
		std::ifstream inputFile(av[1]);
		if (!inputFile.is_open())
		{
			throw std::runtime_error("ifstream: input file cant open");
		}
		std::string line;
		std::getline(inputFile, line);
		if (line.empty() || line != "date | value")
		{
			throw std::runtime_error("input file: incorrect file");
			return (1);
		}
		BitcoinExchange data;
		while (std::getline(inputFile, line))
		{
			process_line(line, data);
		}
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << e.what() << "\n";
	}
	return (0);
}
