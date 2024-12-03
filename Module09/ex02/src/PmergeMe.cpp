/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/10 17:08:36 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/10/20 13:04:52 by juliusdebaa   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"
#include <utility>

// Comparator function for pairs
bool pairComparator(const t_fj &a, const t_fj &b)
{
	return a.first <= b.first; // Compare based on the first element
}

// Binary insertion for using binary search with limited range - Lists
void lstBinaryInsert(std::list<t_fj> &sorted_list, const t_fj &value, std::list<t_fj>::iterator range_start, std::list<t_fj>::iterator range_end)
{
	while (range_start != range_end)
	{
		std::list<t_fj>::iterator mid = std::next(range_start, std::distance(range_start, range_end) / 2);
		if (pairComparator(*mid, value))
		{
			range_start = std::next(mid);
		}
		else
		{
			range_end = mid;
		}
	}
	sorted_list.insert(range_start, value);
}

// insertion for using binary search - Vectors
void vecBinaryInsert(std::vector<t_fj> &vec, const t_fj value)
{
	std::vector<t_fj>::iterator pos;
	pos = std::lower_bound(vec.begin(), vec.end(), value, pairComparator);
	vec.insert(pos, value);
}

// insertion for using binary search from begin to Position (limitng range) - Vectors
void vecBinaryInsertPos(std::vector<t_fj> &vec, const t_fj value, std::vector<t_fj>::iterator range)
{
	std::vector<t_fj>::iterator pos;
	pos = std::lower_bound(vec.begin(), range, value, pairComparator);
	vec.insert(pos, value);
}