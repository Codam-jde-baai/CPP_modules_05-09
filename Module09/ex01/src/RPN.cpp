/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.cpp                             			    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/19 15:41:14 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/10/08 17:52:34 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"
#include <string>
#include <iostream>

/*  constructors */

RPN::RPN(void)
{
}

/*
RPN::RPN(RPN &src) : _stack(src._stack)
{
}

RPN &RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
	{
		this->_stack = rhs._stack;
	}
	return (*this);
}
*/

RPN::~RPN()
{
}

/**
 * @brief calculates RPN, leaves the output of the last operation in the stack.
 */
int RPN::process_input(std::string expression)
{
	std::istringstream ss(expression);
	std::string input;
	while (std::getline(ss, input, ' '))
	{

		if (input.length() > 1)
			throw std::runtime_error("bad input");
		if (std::isdigit(input[0]))
		{
			_stack.push(std::stoi(input));
		}
		else if (input[0] == '+' || input[0] == '-' || input[0] == '/' || input[0] == '*')
		{
			rpn_operation(input[0]);
		}
		else
			throw std::runtime_error("bad input");
	}
	if (_stack.size() != 1)
		throw std::runtime_error("too many or too few numbers in stack");
	int out = _stack.top();
	return (out);
}

/**
 * Clears the stack. removing the output from the last calculation
 */
void RPN::clear_stack(void)
{
	while (_stack.size() > 0)
	{
		_stack.pop();
	}
}

void RPN::rpn_operation(char op)
{
	if (_stack.size() < 2)
		throw std::runtime_error("not enough numbers to perform operation");
	int top = _stack.top();
	_stack.pop();
	int second = _stack.top();
	_stack.pop();
	int out;
	switch (op)
	{
	case '+':
		out = second + top;
		break;
	case '-':
		out = second - top;
		break;
	case '*':
		out = second * top;
		break;
	case '/':
		out = second / top;
		break;
	default:
		throw std::runtime_error("invalid operator token");
	}
	// std::cout << "operation: " << second << "/" << top << " = " << out << std::endl;
	_stack.push(out);
}