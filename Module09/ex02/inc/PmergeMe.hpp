/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/10 17:08:49 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/10/20 13:04:56 by juliusdebaa   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <utility>

/**
 * @typedef t_fj, FordJohnson pairing of 2 integers.
 */
struct t_fj
{
	int first;
	int second;
};

// Comparator function for pairs
bool pairComparator(const t_fj &a, const t_fj &b);

// insertion for using binary search - Vectors
template <typename Container>
void BinaryInsert(Container &cont, const t_fj &value)
{
	typename Container::iterator pos = std::lower_bound(cont.begin(), cont.end(), value, pairComparator);
	cont.insert(pos, value);
}

// insertion for using binary search from begin to Position (limitng range) - Vectors
template <typename Container, typename Iterator>
void BinaryInsertPos(Container &cont, const t_fj &value, Iterator range)
{
	typename Container::iterator pos = std::lower_bound(cont.begin(), range, value, pairComparator);
	cont.insert(pos, value);
}

template <typename Container, typename Iterator>
bool verifySorted(Container &cont)
{
	for (Iterator it = cont.begin(); it != std::prev(cont.end()); ++it)
	{
		if (pairComparator(*(std::next(it)), *it))
		{
			return (false);
		}
	}
	return (true);
}

void lstBinaryInsert(std::list<t_fj> &sorted_list, const t_fj &value, std::list<t_fj>::iterator range_start, std::list<t_fj>::iterator range_end);
void vecBinaryInsert(std::vector<t_fj> &vec, const t_fj value);
void vecBinaryInsertPos(std::vector<t_fj> &vec, const t_fj value, std::vector<t_fj>::iterator range);

#endif /* PMERGEME_HPP */
