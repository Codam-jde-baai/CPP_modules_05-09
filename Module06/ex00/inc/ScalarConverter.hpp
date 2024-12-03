/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/16 15:28:15 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/09/19 11:39:47 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class ScalarConverter
{
private:
	ScalarConverter(void) = delete;
	ScalarConverter(const ScalarConverter &src) = delete;
	ScalarConverter &operator=(const ScalarConverter &rhs) = delete;
	~ScalarConverter(void) = delete;

public:
	// method
	static void convert(std::string const &input);
};
