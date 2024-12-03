/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyFind.tpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/28 15:43:22 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/09/04 12:22:31 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include <algorithm>

/**
 * @warning easyfind assumes the container consists of integers
 */
template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
	{
		throw NotFoundException();
	}
	return it;
}

#endif /*EASYFIND_TPP */