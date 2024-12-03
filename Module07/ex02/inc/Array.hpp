/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/28 14:09:45 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/09/04 12:19:18 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>

template <typename T>
class Array
{
private:
	T *_array;
	std::size_t _n;

public:
	// constructors
	Array(void);
	Array(std::size_t n);
	Array(const Array &src);
	Array &operator=(const Array &rhs);
	~Array(void);

	// member function
	T &operator[](std::size_t n);
	std::size_t size(void);
};

#include "./Array.tpp"
#endif /* ARRAY_HPP */