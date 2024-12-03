/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/04 13:04:12 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/09/04 13:32:03 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>

class NotFoundException : public std::exception
{
public:
	const char *what() const noexcept override
	{
		return "easyfind: not so easy if there is nothing to find";
	}
};

#include "./easyfind.tpp"
#endif /* EASYFIND_HPP */