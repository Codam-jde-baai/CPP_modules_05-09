/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/28 14:09:45 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/09/25 13:02:45 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T>
void iter(T *array, std::size_t len, void (*func)(T &))
{
	for (std::size_t i = 0; i < len; i++)
	{
		func(array[i]);
	}
}

#endif /* ITER_HPP */