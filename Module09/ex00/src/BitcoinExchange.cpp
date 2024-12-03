/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/19 15:41:14 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/10/10 13:42:42 by juliusdebaa   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <iomanip>

BitcoinExchange::BitcoinExchange(void)
{
	std::ifstream inputFile("./data/data.csv");

	if (!inputFile.is_open())
		throw std::runtime_error("constructor: opening the data.csv source file");
	std::string line;
	std::getline(inputFile, line); // skipping the date exchange rate header
	while (std::getline(inputFile, line))
	{
		std::istringstream ss(line);
		std::string date, rate;

		if (std::getline(ss, date, ',') && std::getline(ss, rate))
		{
			_dataset.insert({split_date(date), std::stof(rate)});
		}
	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &src) : _dataset(src._dataset)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
	{
		this->_dataset = rhs._dataset;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

float BitcoinExchange::getRate(s_time date)
{
	std::map<s_time, float>::const_iterator it;

	it = _dataset.find(date);
	while (it == _dataset.end())
	{
		date.day--;
		if (date.day < 1)
		{
			date.month--;
			if (date.month < 1)
			{
				date.year--;
				date.month = 12;
			}
			date.day = 31;
		}
		it = _dataset.find(date);
	}
	return (it->second);
}

s_time split_date(std::string date)
{
	s_time out;

	std::istringstream ss(date);
	std::string day, month, year;
	if (std::getline(ss, year, '-') && std::getline(ss, month, '-') && std::getline(ss, day))
	{
		out.year = std::stoi(year);
		out.month = std::stoi(month);
		out.day = std::stoi(day);
	}
	return (out);
}

void BitcoinExchange::printDataset() const
{
	std::map<s_time, float>::const_iterator it;

	for (it = _dataset.begin(); it != _dataset.end(); ++it)
	{
		const s_time &date = it->first;
		float rate = it->second;

		std::cout << date.year << "-"
				  << std::setw(2) << std::setfill('0') << date.month << "-"
				  << std::setw(2) << std::setfill('0') << date.day << " : "
				  << rate << std::endl;
	}
}