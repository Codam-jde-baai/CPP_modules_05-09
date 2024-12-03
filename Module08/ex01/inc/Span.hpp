/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/04 13:39:44 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/10/17 14:39:08 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>

class Span
{
private:
	const size_t _max;
	std::vector<int> _vec;

public:
	// OCF constructors
	Span(void);
	Span(Span &src);
	Span &operator=(const Span &rhs);
	~Span(void);
	// other constructors
	Span(unsigned int N);

	// member functions
	void addNumber(int nbr);
	void addRange(std::vector<int>::iterator start, std::vector<int>::iterator end);
	unsigned int getMax() const;

	long shortestSpan();
	long longestSpan();

	// testing functions
	void floodSpan();
	void printSpan();

	class maxSize : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class noSpan : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif /* SPAN_HPP */