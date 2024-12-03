/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.tpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/28 15:43:22 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/09/04 12:22:31 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"
#include <cstddef>
#include <stdexcept>

/* constructors */

// Construction with no parameter: Creates an empty array.
template <typename T>
Array<T>::Array(void) : _array(nullptr), _n(0)
{
}

// Construction with an unsigned int n as a parameter: Creates an array of n elementsinitialized by default
template <typename T>
Array<T>::Array(std::size_t n) : _array(nullptr), _n(n)
{
	_array = new T[_n];
}

// Construction by copy and assignment operator. In both cases,
// modifying either the
//  original array or its copy after copying musn’t affect the other array.

template <typename T>
Array<T>::Array(const Array &src) : _array(nullptr), _n(0)
{
	_n = src._n;
	if (_n > 0)
	{
		_array = new T[_n];
		for (std::size_t i = 0; i < _n; i++)
		{
			_array[i] = src._array[i];
		}
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &rhs)
{
	if (this != &rhs)
	{
		delete[] _array;
		_n = rhs._n;
		if (_n > 0)
		{
			_array = new T[_n];
			for (std::size_t i = 0; i < _n; i++)
			{
				_array[i] = rhs._array[i];
			}
		}
		else
			_array = nullptr;
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

// // member function

/**
 * @warning will throw if n is outside of _n range
 */
template <typename T>
T &Array<T>::operator[](std::size_t n)
{
	if (n >= _n)
	{
		throw std::out_of_range("n is greater than the size of the array");
	}
	return (_array[n]);
}

template <typename T>
std::size_t Array<T>::size(void)
{
	return (_n);
}

#endif /*ARRAY_TPP */