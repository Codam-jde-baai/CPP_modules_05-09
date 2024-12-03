/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serializer.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: juliusdebaaij <juliusdebaaij@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/27 15:47:34 by juliusdebaa   #+#    #+#                 */
/*   Updated: 2024/09/19 12:16:54 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>

// Data structure
struct Data
{
	int _dataInt;
	float _dataFloat;
	std::string _dataString;
	char _dataChar;
};

class Serializer
{
private:
	Serializer(void) = delete;
	Serializer(const Serializer &src) = delete;
	Serializer &operator=(const Serializer &rhs) = delete;
	~Serializer(void) = delete;

public:
	// functions
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};
