/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/04 13:39:49 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/10/17 14:39:27 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"
#include <climits>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <ctime>

/* OCF */
Span::Span(void) : _max(UINT_MAX), _vec()
{
}

Span::Span(Span &src) : _max(src._max), _vec(src._vec)
{
}

Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		//_max can not be est since its constant
		this->_vec = rhs._vec;
	}
	return (*this);
}

Span::~Span(void)
{
}

/* Other constructors */
Span::Span(unsigned int max) : _max(max), _vec()
{
}

/* member functions */

void Span::addNumber(int nbr)
{
	if (_vec.size() == _max)
	{
		throw maxSize();
	}
	_vec.push_back(nbr);
}

void Span::addRange(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	size_t rangesize = std::distance(start, end);
	if (_vec.size() + rangesize > _max)
		throw Span::maxSize();

	_vec.insert(_vec.end(), start, end);
}

unsigned int Span::getMax() const
{
	return (_max);
}

/**
 * @note choosing to copy the vector as to not mess with the original order of the vector
 */
long Span::shortestSpan()
{
	if (_vec.size() <= 1)
		throw noSpan();

	long span = UINT_MAX;
	std::vector<int> vecCopy = _vec;
	std::sort(vecCopy.begin(), vecCopy.end());

	for (size_t i = 1; i < vecCopy.size(); i++)
	{
		if (std::abs(static_cast<long>(vecCopy[i]) - static_cast<long>(vecCopy[i - 1])) < span)
			span = std::abs(static_cast<long>(vecCopy[i]) - static_cast<long>(vecCopy[i - 1]));
	}
	return (span);
}

long Span::longestSpan()
{
	if (_vec.size() <= 1)
		throw noSpan();
	int lowest = *_vec.begin();
	int highest = *_vec.begin();
	;
	for (size_t i = 1; i < _vec.size(); i++)
	{
		if (_vec[i] < lowest)
			lowest = _vec[i];
		if (_vec[i] > highest)
			highest = _vec[i];
	}
	return std::abs(static_cast<long>(highest) - static_cast<long>(lowest));
}

/* testing function */

void Span::floodSpan()
{
	srand(time(NULL) * rand());

	for (size_t i = 0; i < _max; i++)
	{
		this->addNumber(rand());
	}
}

void Span::printSpan()
{
	std::cout << "printSpan:" << std::endl;
	for (size_t i = 0; i < _vec.size(); i++)
	{
		std::cout << _vec[i] << std::endl;
	}
}

/* exceptions */

const char *Span::maxSize::what() const throw()
{
	return "\033[31mSpan error: Maximum size reached\033[0m";
}

const char *Span::noSpan::what() const throw()
{
	return "\033[31mSpan error: Not enough elements for a span\033[0m";
}