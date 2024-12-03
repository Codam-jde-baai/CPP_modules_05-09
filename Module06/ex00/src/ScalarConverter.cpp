/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/16 15:34:30 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/09/19 12:12:32 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <math.h>
#include <limits>

// Member function

enum class eType
{
	ERR = 0,
	CHAR = 1,
	INT = 2,
	FLOAT = 3,
	DOUBLE = 4,
	SC_NAN = 5, // scalar converter NAN as NAN is already a defined
	NEG_INF = 6,
	POS_INF = 7
};

static eType string_identifier(std::string const &input);
static void convert_char(std::string const &input);
static void convert_int(std::string const &input);
static void convert_float(std::string const &input);
static void convert_double(std::string const &input);
static void print_nan(void);
static void print_neginf(void);
static void print_posinf(void);

void ScalarConverter::convert(std::string const &input)
{
	eType type = string_identifier(input);

	if (type == eType::ERR)
	{
		std::cerr << "Please input 1 int, char, float or double to convert" << std::endl;
		return;
	}
	switch (type)
	{
	case eType::CHAR:
		convert_char(input);
		break;
	case eType::INT:
		convert_int(input);
		break;
	case eType::FLOAT:
		convert_float(input);
		break;
	case eType::DOUBLE:
		convert_double(input);
		break;
	case eType::SC_NAN:
		print_nan();
		break;
	case eType::NEG_INF:
		print_neginf();
		break;
	case eType::POS_INF:
		print_posinf();
		break;
	default:
		break;
	}
}

static eType string_identifier(std::string const &input)
{

	if (input.empty())
		return (eType::ERR);
	// identify edge cases
	{
		const std::string pseudo_literals[6] = {"nan", "nanf", "-inf", "-inff", "+inf", "+inff"};
		const eType pseudo_types[3] = {eType::SC_NAN, eType::NEG_INF, eType::POS_INF};
		for (int i = 0; i < 6; i += 2)
		{
			if (input == pseudo_literals[i] || input == pseudo_literals[i + 1])
			{
				return pseudo_types[i / 2];
			}
		}
	}
	// single characters
	if (input.size() == 1)
	{
		if (input.front() == '+' || input.front() == '-')
			return (eType::ERR);
		if (isprint(input.front()) && !std::isdigit(input.front()))
			return (eType::CHAR);
		return (eType::INT);
	}
	// rest of the identifcation
	size_t i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	if ((isprint(input[i]) && !std::isdigit(input[i])))
		return (eType::ERR);
	for (; i < input.size(); i++)
	{
		if (!std::isdigit(input[i]))
			break;
	}
	if (i == input.size())
		return (eType::INT);
	if (input[i] == 'f' && i + 1 == input.size())
		return (eType::FLOAT);
	if (input[i] == '.')
	{
		i++;
		if (!std::isdigit(input[i]))
			return (eType::ERR);
		for (; i < input.size(); i++)
		{
			if (input[i] == 'f')
			{
				if (i + 1 == input.size())
					return (eType::FLOAT);
				return (eType::ERR);
			}
			if (!std::isdigit(input[i]))
				break;
		}
		if (i == input.size())
			return (eType::DOUBLE);
	}
	return (eType::ERR);
}

static void convert_char(std::string const &input)
{
	std::cout << "char: " << input[0] << std::endl;
	std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(input[0]) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(input[0]) << std::endl;
}
static void convert_int(std::string const &input)
{
	try
	{
		int num = std::stoi(input);

		if (num >= 32 && num <= 126)
		{
			std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
		}
		else
		{
			std::cout << "char: Non displayable" << std::endl;
		}
		std::cout << "int: " << num << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(num) << std::endl;
	}
	catch (const std::invalid_argument &e)
	{
		std::cerr << "Invalid argument: " << e.what() << std::endl;
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << "Out of range error: " << e.what() << std::endl;
		std::cout << "Please keep the number in int range" << std::endl;
	}
}

static void convert_float(std::string const &input)
{
	try
	{
		float num = std::stof(input);

		if (num >= 32 && num <= 126)
		{
			std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
		}
		else
		{
			std::cout << "char: Non displayable" << std::endl;
		}
		std::cout << "int: " << static_cast<int>(num) << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << num << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(num) << std::endl;
	}
	catch (const std::invalid_argument &e)
	{
		std::cerr << "Invalid argument: " << e.what() << std::endl;
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << "Out of range error: " << e.what() << std::endl;
	}
}

static void convert_double(std::string const &input)
{
	try
	{
		float num = std::stod(input);

		if (num >= 32 && num <= 126)
		{
			std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
		}
		else
		{
			std::cout << "char: Non displayable" << std::endl;
		}
		std::cout << "int: " << static_cast<int>(num) << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << num << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(num) << std::endl;
	}
	catch (const std::invalid_argument &e)
	{
		std::cerr << "Invalid argument: " << e.what() << std::endl;
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << "Out of range error: " << e.what() << std::endl;
	}
}

static void print_nan(void)
{
	float nanf_value = std::numeric_limits<float>::quiet_NaN();
	double nan_value = std::numeric_limits<double>::quiet_NaN();
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << nanf_value << "f" << std::endl;
	std::cout << "double: " << nan_value << std::endl;
}

static void print_neginf(void)
{
	float neginf_valuef = -std::numeric_limits<float>::infinity();
	double neginf_value = -std::numeric_limits<double>::infinity();
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << neginf_valuef << "f" << std::endl;
	std::cout << "double: " << neginf_value << std::endl;
}

static void print_posinf(void)
{
	float posinf_valuef = std::numeric_limits<float>::infinity();
	double posinf_value = std::numeric_limits<double>::infinity();
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << posinf_valuef << "f" << std::endl;
	std::cout << "double: " << posinf_value << std::endl;
}
