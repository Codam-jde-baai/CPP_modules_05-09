/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/28 14:09:31 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/09/25 13:10:28 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"
#include <iostream>
#include <stdexcept>

int main(void)
{
	//Default constructor
	Array<int> arr1;
	std::cout << "Default constructor" << std::endl;
	std::cout << "Size of arr1: " << arr1.size() << std::endl;
	std::cout << std::endl;

	//Constructor with size
	std::size_t size = 5;
	Array<int> arr2(size);
	std::cout << "Constructor with size" << std::endl;
	std::cout << "Size of arr2: " << arr2.size() << std::endl;
	for (std::size_t i = 0; i < arr2.size(); ++i)
	{
		arr2[i] = i * 2; // Assigning 1 - 5 x 2
		std::cout << "arr2[" << i << "]: " << arr2[i] << std::endl;
	}
	std::cout << std::endl;

	//Copy constructor
	Array<int> arr3 = arr2;
	std::cout << "Copy constructor" << std::endl;
	std::cout << "Size of arr3: " << arr3.size() << std::endl;
	for (std::size_t i = 0; i < arr3.size(); ++i)
	{
		std::cout << "arr3[" << i << "]: " << arr3[i] << std::endl;
	}
	std::cout << std::endl;

	// Assignment operator
	Array<int> arr4;
	arr4 = arr3;
	std::cout << "Assignment operator" << std::endl;
	std::cout << "Size of arr4: " << arr4.size() << std::endl;
	for (std::size_t i = 0; i < arr4.size(); ++i)
	{
		std::cout << "arr4[" << i << "]: " << arr4[i] << std::endl;
	}
	std::cout << std::endl;

	// Modify original array and check if copy is unaffected
	arr2[0] = 100;
	std::cout << "Modify original array" << std::endl;
	std::cout << "arr2[0]: " << arr2[0] << std::endl;
	std::cout << "arr3[0] (should be unaffected): " << arr3[0] << std::endl;
	std::cout << std::endl;

	// Bounds checking
	try
	{
		std::cout << "Bounds checking" << std::endl;
		std::cout << "Attempting to access out-of-bounds element arr2[10]..." << std::endl;
		std::cout << arr2[10] << std::endl; // This should throw an exception or handle out of bounds
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}