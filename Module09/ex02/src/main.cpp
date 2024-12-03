/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 11:47:20 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/10/20 13:08:11 by juliusdebaa   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// using std::vector
// using std::list

/**
 * 1. store all inputs as pairs in a vector
 * 2. Apply comparison on each pair. moving the bigger of the 2 integers into the first position
 * 3. Sort the list using a binaryinsertion sort. binary search for the smallest integer comparing if each number is smaller or bigger
 * 4. Insert the paired value into the vector;
 */

#include "../inc/PmergeMe.hpp"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <deque>

template <typename Container>
Container binary_method(int ac, char **av)
{
	t_fj p;
	Container cont;
	t_fj odd_number;
	t_fj second;
	for (int i = 1; i < ac - 1; i += 2)
	{
		p.first = std::stoi(av[i]);
		p.second = std::stoi(av[i + 1]);
		if (p.first < 0 || p.second < 0)
			throw std::runtime_error("negative numbr");
		if (p.second > p.first)
			std::swap(p.first, p.second);
		BinaryInsert(cont, p);
	}
	if (ac % 2 == 0)
	{
		odd_number.first = std::stoi(av[ac - 1]);
		if (odd_number.first < 0)
			throw std::runtime_error("negative numbr");
	}
	u_int end = cont.size() * 2;
	for (u_int i = 0; i < end; i += 2)
	{
		second.first = cont[i].second;
		BinaryInsertPos(cont, second, cont.begin() + i);
	}
	if (ac % 2 == 0)
		BinaryInsert(cont, odd_number);
	return (cont);
}

std::list<t_fj> lstBinary_method(int ac, char **av)
{

	std::list<t_fj> lst;
	t_fj p;
	t_fj odd_number;
	t_fj second;

	for (int i = 1; i < ac - 1; i += 2)
	{
		p.first = std::stoi(av[i]);
		p.second = std::stoi(av[i + 1]);
		if (p.first < 0 || p.second < 0)
			throw std::runtime_error("negative numbr");
		if (p.second > p.first)
			std::swap(p.first, p.second);
		lstBinaryInsert(lst, p, lst.begin(), lst.end());
	}
	if (ac % 2 == 0)
	{
		odd_number.first = std::stoi(av[ac - 1]);
		if (odd_number.first < 0)
			throw std::runtime_error("negative numbr");
	}
	std::list<t_fj>::iterator it = lst.begin();
	while (it != lst.end())
	{
		second.first = it->second;
		lstBinaryInsert(lst, second, lst.begin(), it);
		++it;
	}
	if (ac % 2 == 0)
		lstBinaryInsert(lst, odd_number, lst.begin(), lst.end());
	return (lst);
}

std::vector<t_fj> vector_method(int ac, char **av)
{
	t_fj p;
	std::vector<t_fj> vec;
	t_fj odd_number;
	t_fj second;
	for (int i = 1; i < ac - 1; i += 2)
	{
		p.first = std::stoi(av[i]);
		p.second = std::stoi(av[i + 1]);
		if (p.first < 0 || p.second < 0)
			throw std::runtime_error("negative numbr");
		if (p.second > p.first)
			std::swap(p.first, p.second);
		vecBinaryInsert(vec, p);
	}
	if (ac % 2 == 0)
	{
		odd_number.first = std::stoi(av[ac - 1]);
		if (odd_number.first < 0)
			throw std::runtime_error("negative numbr");
	}
	u_int end = vec.size() * 2;
	for (u_int i = 0; i < end; i += 2)
	{
		second.first = vec[i].second;
		vecBinaryInsertPos(vec, second, vec.begin() + i);
	}
	if (ac % 2 == 0)
		vecBinaryInsert(vec, odd_number);
	return (vec);
}

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "Please provide input ie. \" ./PmergeMe 3 5 9 7 4\"" << std::endl;
		return 0;
	}
	try
	{
		/* time checking */
		std::chrono::high_resolution_clock::time_point start;
		std::chrono::high_resolution_clock::time_point stop;
		std::chrono::duration<double, std::micro> vecDuration;
		std::chrono::duration<double, std::micro> dequeDuration;
		std::chrono::duration<double, std::micro> lstDuration;
		std::chrono::duration<double, std::micro> noTemplateVecDuration;

		start = std::chrono::high_resolution_clock::now();
		std::vector<t_fj> vec = binary_method<std::vector<t_fj>>(ac, av);
		stop = std::chrono::high_resolution_clock::now();
		vecDuration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		start = std::chrono::high_resolution_clock::now();
		std::deque<t_fj> deq = binary_method<std::deque<t_fj>>(ac, av);
		stop = std::chrono::high_resolution_clock::now();
		dequeDuration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		start = std::chrono::high_resolution_clock::now();
		std::list<t_fj> lst = lstBinary_method(ac, av);
		stop = std::chrono::high_resolution_clock::now();
		lstDuration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		start = std::chrono::high_resolution_clock::now();
		std::vector<t_fj> noTemplateVec = vector_method(ac, av);
		stop = std::chrono::high_resolution_clock::now();
		noTemplateVecDuration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

		std::cout << "Before:       ";
		for (int i = 1; i < ac; ++i)
		{
			std::cout << " " << av[i];
		}
		std::cout << std::endl;

		std::cout << "After[vec]:   ";
		for (std::vector<t_fj>::iterator it = vec.begin(); it != vec.end(); it++)
		{
			std::cout << " " << it->first;
		}
		std::cout << std::endl;

		std::cout << "After[deque]: ";
		for (std::deque<t_fj>::iterator it = deq.begin(); it != deq.end(); it++)
		{
			std::cout << " " << it->first;
		}
		std::cout << std::endl;

		std::cout << "After[lst]:   ";
		for (std::list<t_fj>::iterator it = lst.begin(); it != lst.end(); it++)
		{
			std::cout << " " << it->first;
		}
		std::cout << std::endl;

		std::cout << "After[vector[no template]]:   ";
		for (std::vector<t_fj>::iterator it = noTemplateVec.begin(); it != noTemplateVec.end(); it++)
		{
			std::cout << " " << it->first;
		}
		std::cout << std::endl;

		std::cout << "Time to process a range of " << (ac - 1) << " elements with std::[vector]: "
				  << std::fixed << std::setprecision(5) << vecDuration.count() << " us" << std::endl;
		std::cout << "Time to process a range of " << (ac - 1) << " elements with std::[deque]:  "
				  << std::fixed << std::setprecision(5) << dequeDuration.count() << " us" << std::endl;
		std::cout << "Time to process a range of " << (ac - 1) << " elements with std::[list]:   "
				  << std::fixed << std::setprecision(5) << lstDuration.count() << " us" << std::endl;
		std::cout << "Time to process a range of " << (ac - 1) << " elements with std::[vec[no template]]:   "
				  << std::fixed << std::setprecision(5) << noTemplateVecDuration.count() << " us" << std::endl;
		std::cout << (verifySorted<std::vector<t_fj>, std::vector<t_fj>::iterator>(vec) ? "\033[1;32mVector sorted correctly\033[0m" : "\033[1;31mVector sorted incorrectly\033[0m") << std::endl;
		std::cout << (verifySorted<std::deque<t_fj>, std::deque<t_fj>::iterator>(deq) ? "\033[1;32mDeque sorted correctly\033[0m" : "\033[1;31mDeque sorted incorrectly\033[0m") << std::endl;
		std::cout << (verifySorted<std::list<t_fj>, std::list<t_fj>::iterator>(lst) ? "\033[1;32mList sorted correctly\033[0m" : "\033[1;31mList sorted incorrectly\033[0m") << std::endl;
		std::cout << (verifySorted<std::vector<t_fj>, std::vector<t_fj>::iterator>(noTemplateVec) ? "\033[1;32mNo Template Vector sorted correctly\033[0m" : "\033[1;31mNo Template Vector sorted incorrectly\033[0m") << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << "Error" << '\n';
	}
	return (0);
}

/**
 * an int main to use with unit_test.sh to check if the program provides the right order
 * comment in this main and out the other
 * comment in a select either the vector or the list and then run the unit_test.sh
 */

// int main(int ac, char **av)
// {
// 	/* test the vector */
// 	std::vector<t_fj> vec = binary_method<std::vector<t_fj>>(ac, av);
// 	for (std::vector<t_fj>::iterator it = vec.begin(); it != vec.end(); it++)
// 	{
// 		std::cout << " " << it->first;
// 	}
// 	std::cout << std::endl;
// 	/* test the list */
// 	std::list<t_fj> lst = list_method(ac, av);
// 	for (std::list<t_fj>::iterator it = lst.begin(); it != lst.end(); it++)
// 	{
// 		std::cout << " " << it->first;
// 	}
// 	std::cout << std::endl;
// }