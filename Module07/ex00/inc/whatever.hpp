/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   whatever.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/28 14:09:45 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/09/25 13:02:13 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &x, T &y)
{
	T temp;
	temp = y;
	y = x;
	x = temp;
}

template <typename T>
T min(const T x, const T y)
{
	if (x < y)
		return (x);
	return (y);
}

template <typename T>
T max(const T x, const T y)
{
	if (x > y)
		return (x);
	return (y);
}

#endif /* WHATEVER_HPP */