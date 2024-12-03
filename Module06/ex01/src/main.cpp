/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/29 15:38:17 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/09/19 12:20:10 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Serializer.hpp"
#include <iomanip>

// reinterpet cast exercise

int main(void)
{
	Data myData;
	myData._dataInt = 42;
	myData._dataFloat = 42.42f;
	myData._dataString = "Serialization";
	myData._dataChar = 'A';

	// Serialize the Data pointer
	uintptr_t serialized = Serializer::serialize(&myData);
	// Deserialize back to a Data pointer
	Data *deserialized = Serializer::deserialize(serialized);

	// printing all pointers -- all pointers should be the same
	std::cout << "Number serialized pointer: " << std::setw(20) << serialized << std::endl;
	std::cout << "Original pointer address: " << std::setw(20) << &myData << std::endl;
	std::cout << "Hexadecimal serialized pointer: " << std::setw(2) << "0x" << std::hex << serialized << std::endl;
	std::cout << "Deserialized pointer address: " << std::setw(16) << &myData << std::endl;
	std::cout << std::dec;
	if (deserialized == &myData) // in case all are the same print the data content
	{
		std::cout << "\033[33mData variables after deserialization:\033[0m" << std::endl;
		std::cout << "Int: " << deserialized->_dataInt << std::endl;
		std::cout << "Float: " << deserialized->_dataFloat << std::endl;
		std::cout << "String: " << deserialized->_dataString << std::endl;
		std::cout << "Char: " << deserialized->_dataChar << std::endl;
	}

	return (0);
}
